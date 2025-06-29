import cv2
import numpy as np
import time
import os
from datetime import datetime

class SimpleVideoClassifier:
    def __init__(self):
        self.face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
        self.eye_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_eye.xml')
        
        self.owner_face_data = None
        self.pet_data = None
        self.has_pet = False
        self.consent_given = False

        self.last_detection_time = time.time()
        self.detection_history = []
        self.background_subtractor = cv2.createBackgroundSubtractorMOG2()
        
    def get_consent(self):
        """Get user consent before starting the system."""
        print("\n=== Privacy Notice ===")
        print("This AI Video Classification System will:")
        print("1. Access your webcam")
        print("2. Process video in real-time")
        print("3. Detect faces and movement")
        print("4. NOT store any data permanently")
        print("5. NOT transmit any data")
        print("6. Only process data locally on your computer")
        print("\nThis system respects ethical guidelines and prioritizes user privacy.")
        print("You can stop the system at any time by pressing 'q'.")
        print("\nDo you consent to these terms? (yes/no): ")
        
        while True:
            response = input().lower().strip()
            if response in ['yes', 'y']:
                self.consent_given = True
                print("Thank you for your consent. Starting the system...")
                return True
            elif response in ['no', 'n']:
                print("System will not start without consent. Goodbye!")
                return False
            else:
                print("Please answer 'yes' or 'no': ")

    def register_owner(self):
        """Register the owner's face for recognition."""
        print("\n=== Owner Registration ===")
        print("Please look at the camera to register your face.")
        print("The system will capture your reference image when it detects a stable face.")
        print("Press 'q' to skip this step.")
        
        cap = cv2.VideoCapture(0)
        if not cap.isOpened():
            print("Error: Could not open webcam")
            return False
            
        stable_detections = 0
        required_stability = 10  # Number of consecutive detections needed
        
        while True:
            ret, frame = cap.read()
            if not ret:
                print("Failed to capture video")
                break
                
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            faces = self.face_cascade.detectMultiScale(gray, 1.3, 5)
            
            for (x, y, w, h) in faces:
                cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)
                stable_detections += 1
                
                if stable_detections >= required_stability:
                    self.owner_face_data = {
                        'region': gray[y:y+h, x:x+w],
                        'size': (w, h),
                        'position': (x, y),
                        'registered': True
                    }
                    print("Owner face registered successfully!")
                    cap.release()
                    cv2.destroyAllWindows()
                    return True
            
            if len(faces) == 0:
                stable_detections = max(0, stable_detections - 1)
            
            cv2.putText(frame, f"Stability: {stable_detections}/{required_stability}", 
                       (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(frame, "Look at camera steadily", 
                       (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.imshow('Register Owner', frame)
            
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
                
        cap.release()
        cv2.destroyAllWindows()
        return False

    def register_pet(self):
        """Register the pet's visual characteristics."""
        print("\n=== Pet Registration ===")
        print("Do you have a pet you'd like to include in the classification? (yes/no): ")
        
        while True:
            response = input().lower().strip()
            if response in ['yes', 'y']:
                self.has_pet = True
                break
            elif response in ['no', 'n']:
                print("No pet registered.")
                return False
            else:
                print("Please answer 'yes' or 'no': ")
        
        print("\nPlease show your pet to the camera to register them.")
        print("Position your pet in the center of the frame and keep them still.")
        print("The system will automatically capture when it detects a stable pet.")
        print("Press 'q' to skip this step.")
        
        cap = cv2.VideoCapture(0)
        if not cap.isOpened():
            print("Error: Could not open webcam")
            return False
            
        bg_subtractor = cv2.createBackgroundSubtractorMOG2()
        stable_detections = 0
        required_stability = 15 
        last_pet_position = None
        position_tolerance = 50  

        print("Learning background... please keep the area clear for 2 seconds")
        for i in range(60): 
            ret, frame = cap.read()
            if ret:
                bg_subtractor.apply(frame)
            cv2.waitKey(33)
        
        print("Background learned. Now show your pet!")
        
        while True:
            ret, frame = cap.read()
            if not ret:
                print("Failed to capture video")
                break
            
            fg_mask = bg_subtractor.apply(frame)
            
            kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
            fg_mask = cv2.morphologyEx(fg_mask, cv2.MORPH_OPEN, kernel)
            fg_mask = cv2.morphologyEx(fg_mask, cv2.MORPH_CLOSE, kernel)
            
            contours, _ = cv2.findContours(fg_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            
            valid_contours = [c for c in contours if cv2.contourArea(c) > 1000 and cv2.contourArea(c) < 50000]
            
            current_pet_detected = False
            
            if valid_contours:
                largest_contour = max(valid_contours, key=cv2.contourArea)
                x, y, w, h = cv2.boundingRect(largest_contour)
                
                current_position = (x + w//2, y + h//2)  # Center point
                
                if last_pet_position is None:
                    last_pet_position = current_position
                    stable_detections = 1
                    current_pet_detected = True
                else:
                    distance = ((current_position[0] - last_pet_position[0])**2 + 
                               (current_position[1] - last_pet_position[1])**2)**0.5
                    
                    if distance <= position_tolerance:
                        stable_detections += 1
                        current_pet_detected = True
                        
                        if stable_detections >= required_stability:
                            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
                            self.pet_data = {
                                'region': gray[y:y+h, x:x+w],
                                'size': (w, h),
                                'position': (x, y),
                                'registered': True,
                                'reference_frame': gray.copy()
                            }
                            print("Pet registered successfully!")
                            cap.release()
                            cv2.destroyAllWindows()
                            return True
                    else:
                        stable_detections = 1
                        last_pet_position = current_position
                        current_pet_detected = True
                
                cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 255), 2)
                cv2.putText(frame, "Pet Detected", (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)
            
            if not current_pet_detected:
                stable_detections = max(0, stable_detections - 1)
                if stable_detections == 0:
                    last_pet_position = None
            
            cv2.putText(frame, f"Stability: {stable_detections}/{required_stability}", 
                       (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(frame, "Keep your pet still in the frame", 
                       (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(frame, "Press 'q' to skip", 
                       (10, 110), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)
            
            cv2.imshow('Register Pet', frame)
            
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
                
        cap.release()
        cv2.destroyAllWindows()
        return False

    def classify_scene(self, frame):
        """Classify what's currently in the scene."""
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = self.face_cascade.detectMultiScale(gray, 1.3, 5)
        
        classifications = []
        detected_objects = []
        
        if len(faces) > 0:
            for i, (x, y, w, h) in enumerate(faces):
                if self.owner_face_data and self.owner_face_data['registered']:
                    face_region = gray[y:y+h, x:x+w]
                    if self._is_similar_to_owner(face_region, (w, h)):
                        classifications.append("Owner")
                    else:
                        classifications.append("Other Person")
                else:
                    classifications.append("Person (Unknown)")
                detected_objects.append(('face', (x, y, w, h)))
        
        if self.pet_data and self.pet_data['registered']:
            pet_detected = self._detect_pet(frame, gray)
            if pet_detected:
                x, y, w, h = pet_detected
                classifications.append("Pet")
                detected_objects.append(('pet', (x, y, w, h)))
        
        if not classifications:
            classifications.append("Nobody")
        
        return classifications, detected_objects

    def _detect_pet(self, frame, gray):
        """Detect pet using motion detection and size filtering."""
        fg_mask = self.background_subtractor.apply(frame)
        
        contours, _ = cv2.findContours(fg_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        
        valid_contours = [c for c in contours if cv2.contourArea(c) > 500 and cv2.contourArea(c) < 30000]
        
        if valid_contours:
            largest_contour = max(valid_contours, key=cv2.contourArea)
            x, y, w, h = cv2.boundingRect(largest_contour)

            faces = self.face_cascade.detectMultiScale(gray[y:y+h, x:x+w], 1.3, 5)
            if len(faces) == 0:  
                return (x, y, w, h)
        
        return None

    def _is_similar_to_owner(self, face_region, face_size):
        """Simple similarity check - in practice, you'd use more sophisticated methods."""
        if not self.owner_face_data:
            return False
            
        owner_size = self.owner_face_data['size']
        size_similarity = min(face_size[0]/owner_size[0], owner_size[0]/face_size[0]) * \
                         min(face_size[1]/owner_size[1], owner_size[1]/face_size[1])
        
        return size_similarity > 0.7

    def run_classification(self):
        """Run the main classification loop."""
        if not self.consent_given:
            print("Consent not given. Exiting...")
            return

        print("\n=== Starting Real-time Classification ===")
        print("The system is now running. Classifications will appear on screen.")
        print("Press 'q' to quit the application.")
        
        cap = cv2.VideoCapture(0)
        if not cap.isOpened():
            print("Error: Could not open webcam")
            return
            
        while True:
            ret, frame = cap.read()
            if not ret:
                print("Failed to capture video")
                break

            classifications, detected_objects = self.classify_scene(frame)

            for obj_type, (x, y, w, h) in detected_objects:
                if obj_type == 'face':
                    color = (0, 255, 0) if "Owner" in str(classifications) else (0, 0, 255)
                    label = next((c for c in classifications if c in ["Owner", "Other Person", "Person (Unknown)"]), "Person")
                elif obj_type == 'pet':
                    color = (255, 0, 255)  # Magenta for pets
                    label = "Pet"
                
                cv2.rectangle(frame, (x, y), (x+w, y+h), color, 2)
                cv2.putText(frame, label, (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)
            
            if classifications:
                main_classification = classifications[0] if len(classifications) == 1 else f"Multiple: {', '.join(set(classifications))}"
            else:
                main_classification = "Nobody"
                
            cv2.putText(frame, f"Status: {main_classification}", (10, 30), 
                       cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
            
            # Add timestamp
            timestamp = datetime.now().strftime("%H:%M:%S")
            cv2.putText(frame, f"Time: {timestamp}", (10, frame.shape[0] - 10), 
                       cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
            
            # Display the frame
            cv2.imshow('AI Video Classifier - Press Q to quit', frame)
            
            # Break loop on 'q' press
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        
        cap.release()
        cv2.destroyAllWindows()
        print("Classification system stopped. Thank you for using our ethical AI system!")

def main():
    print("=== Real-time AI Video Classification System ===")
    print("This system demonstrates ethical AI practices with user privacy protection.")
    
    classifier = SimpleVideoClassifier()
    
    if classifier.get_consent():
        if classifier.register_owner():
            classifier.register_pet()
            classifier.run_classification()
        else:
            print("Owner registration failed. Cannot proceed without reference data.")
    else:
        print("System terminated due to lack of consent.")

if __name__ == "__main__":
    main() 