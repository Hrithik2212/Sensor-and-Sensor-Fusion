
%% Aim : To design an Inertial Measurment Unit with Arduino Uno and MPU9250

%% Connecting withArduino by creating an Arduino Object 

a = arduino('COM6','Uno','Libraries','I2C');

%% Creatde the MPU Sensor Object 
fs = 100;% sample rate in Hz
imu = mpu9250(a,"SampleRate",fs,'OutputFormat','matrix');


%% Reading the values from Magnetometer and removing the hard Iron Distortions 

tic;
stopTimer = 100;
magReadings=[];
while(toc<stopTimer)
    % Rotate the sensor around x axis from 0 to 360 degree.
    % Take 2-3 rotations to improve accuracy.
    % For other axes, rotate around that axis.
    [accel,gyro,mag] = read(imu);
    magReadings = [magReadings;mag];
end

magx_min = min(magReadings(:,1));
magx_max = max(magReadings(:,1));
magx_correction = (magx_max+magx_min)/2;

magy_min = min(magReadings(:,2));
magy_max = max(magReadings(:,2));
magy_correction = (magy_max+magy_min)/2;

magz_min = min(magReadings(:,1));
magz_max = max(magReadings(:,1));
magz_correction = (magz_max+magz_min)/2;

[accel,gyro,mag] = readSensorDataMPU9250(imu,magx_correction,magy_correction,magz_correction);

% GyroscopeNoise and AccelerometerNoise is determined from datasheet.
GyroscopeNoiseMPU9250 = 3.0462e-06; % GyroscopeNoise (variance value) in units of rad/s
AccelerometerNoiseMPU9250 = 0.0061; % AccelerometerNoise(variance value)in units of m/s^2
viewer = HelperOrientationViewer('Title',{'AHRS Filter'});
FUSE = ahrsfilter('SampleRate',imu.SampleRate, 'GyroscopeNoise',GyroscopeNoiseMPU9250,'AccelerometerNoise',AccelerometerNoiseMPU9250);
stopTimer = 100;

% Use ahrsfilter to estimate orientation and update the viewer as the
% sensor moves for time specified by stopTimer

tic;
while(toc < stopTimer)
    [accel,gyro,mag] = readSensorDataMPU9250(imu);
    rotators = FUSE(accel,gyro,mag);
    for j = numel(rotators)
        viewer(rotators(j));
    end
end

function [accel,gyro,mag] = readSensorDataMPU9250(imu,magx_correction,magy_correction,magz_correction)
    accel = [-accel(:,2), -accel(:,1), accel(:,3)];
    gyro = [gyro(:,2), gyro(:,1), -gyro(:,3)];
    mag = [mag(:,1)-magx_correction, mag(:, 2)- magy_correction, mag(:,3)-magz_correction];
end


