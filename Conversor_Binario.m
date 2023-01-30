%%Programa de comunicación serial por: Alberto González Moreno
clc
clear all 
close all
%Restea todos los puertos
instrreset
s = serial('COM3','BaudRate',9600);
s.Terminator = 0;
%Abre el puerto serial 
fopen(s);
while true
C = fscanf(s,"%s");
N = str2num(C);
B = dec2bin(N,16); %% Se envian datos de 16 bits para que quepan en el registro del comparador del PWM
txt = [num2str(B) ','];
fprintf(s,txt);
end
