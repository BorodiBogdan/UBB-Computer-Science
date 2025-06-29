# Real-time AI Video Classification System

This system uses computer vision and machine learning to classify in real-time:

- The laptop owner
- The owner's pet
- Other people
- No one present

## Privacy and Ethics

This system is designed with privacy and ethics in mind:

- All processing is done locally on your computer
- No data is stored or transmitted
- The system requires explicit consent before starting
- You can stop the system at any time

## Setup Instructions

1. Install Python 3.8 or higher
2. Create a virtual environment:
   ```
   python -m venv venv
   venv\Scripts\Activate.ps1  # On Windows
   ```
3. Install the required dependencies:
   ```
   pip install opencv-python scikit-learn
   ```

## Training the System

### Method 1: Folder-based Training (Recommended)

1. **Prepare training images:**

   - Create folders: `human-img/` and `pet-img/`
   - Add 5-10 photos of the laptop owner to `human-img/`
   - Add 5-10 photos of your pet to `pet-img/`
   - Supported formats: jpg, jpeg, png, bmp

2. **Use the capture tool (optional):**

   ```
   python capture_training_images.py
   ```

   - Press 'H' for human mode, 'P' for pet mode
   - Press SPACE to capture images
   - Press 'Q' to quit

3. **Run the trained classifier:**
   ```
   python trained_video_classifier.py
   ```

### Method 2: Real-time Registration

Run the simple classifier for real-time registration:

```
python simple_video_classifier.py
```

## Features

### Trained System (`trained_video_classifier.py`):

- ✅ **Multi-image training** from folders
- ✅ **SIFT feature extraction** for robust recognition
- ✅ **Histogram and edge analysis**
- ✅ **Confidence scores** displayed
- ✅ **Automatic face detection** for humans
- ✅ **Motion-based pet detection**

### Simple System (`simple_video_classifier.py`):

- ✅ **Real-time registration** of owner and pet
- ✅ **Automatic stability detection**
- ✅ **Basic similarity matching**

## Usage

1. When you run the system, it will ask for your consent
2. The system trains from the images in your folders
3. Real-time classification starts automatically
4. Press 'q' to quit the application

## File Structure

```
├── human-img/           # Training images of the laptop owner
├── pet-img/             # Training images of your pet
├── trained_video_classifier.py    # Main trained system
├── simple_video_classifier.py     # Simple real-time system
├── capture_training_images.py     # Helper tool for capturing images
├── requirements.txt     # Dependencies
└── README.md           # This file
```

## Technical Details

The system uses:

- **OpenCV** for computer vision and face detection
- **SIFT (Scale-Invariant Feature Transform)** for feature extraction
- **Histogram analysis** for color and intensity patterns
- **Edge detection** for shape analysis
- **Motion detection** for pet identification
- **Machine learning similarity** for classification

## Note

This system is for educational purposes only. Please ensure you have permission from anyone whose image might be captured by the webcam.
