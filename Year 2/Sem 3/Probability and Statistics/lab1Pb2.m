x = 1:0.01:3;

y1 = (x.^5) / 10;
y2 = x.*sin(x);
y3 = cos(x);

subplot(3,1,1);
plot(x, y1, 'r');
xlabel('x-axis');
ylabel('y1 = (x^5) / 10');
title('Plot 1:');
grid on;

subplot(3,1,2);
plot(x, y2, 'b');
xlabel('x-axis');
ylabel('y2 = x * sin(x)');
title('Plot 2:');
grid on;

subplot(3,1,3);
plot(x, y3, 'y');
xlabel('x-axis');
ylabel('y3 = cos(x)');
title('Plot 3:');
grid on;

