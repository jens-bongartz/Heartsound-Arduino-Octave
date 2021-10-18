t = 0:1/1000:5;
y = sin(2*pi*200*t);
#y = 0.25 * randn (2, 44100);
soundsc(adc_array(1000:end),1000);
##adc_norm = adc_array / max(adc_array);
##player = audioplayer (adc_norm,1000, 16);
##play (player);

#sound(y)