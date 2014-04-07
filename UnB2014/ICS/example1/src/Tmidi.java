

import java.awt.*;
import java.applet.Applet;
import java.text.*;


/**
 * @author Aluizio Arcela
 * @version 0.9 [18/04/2008]
 * @version 0.8 [24/09/2007]
 * @version 0.6 [06/03/1999]
 *
 */

public class Tmidi extends Applet
{
    MidiJS oM; 
    int canal       = 0,
        nota        = 60,
        veloc       = 110,
        pan         = 64,
        instrumento = 0;        

        double hertz=0;
    
        boolean percussao = false;

        Color  corPadrao  = new Color(210,210,210);
        Color  corFrente  = new Color(232,232,232);
        Color  corPlay    = new Color(200,230,200);
        Color  corStop    = new Color(240,180,180);
        Color  corPercON  = new Color(210,210,210);
        Color  corPercOFF = new Color(210,210,210);
        Color  corGM      = new Color(210,210,230);

        final int largura = 195,
                  altura  = 290;

        Botao bansom =    new Botao( 10,  30,  800, 740, corFrente, "");   

        int hp = 485;
        int xp = 20;

        Botao stop  =     new Botao( xp+0*45,  hp,   40, 20,  corStop, "stop",  1, 2, 9);
        Botao play1  =    new Botao( xp+2*45,  hp,   40,  20, corPadrao,    "nota +",       -2, 2, 9);
        Botao play3  =    new Botao( xp+1*45,  hp,   40,  20, corPadrao,    "nota -",       -2, 2, 9);

        Botao ins2  =     new Botao( xp+4*45,  hp,   40,  20, corPadrao,    "ins -", 0, 0, 9);
        Botao ins1  =     new Botao( xp+5*45,  hp,   40,  20, corPadrao,    "ins +", 0, 0, 9);

        Botao intens2  =  new Botao( xp+7*45,  hp,   40,  20, corPadrao,   "loud-",  -6, 2, 9);
        Botao intens1  =  new Botao( xp+8*45,  hp,   40,  20, corPadrao,   "loud+",  -6, 2, 9);

        Botao pan1  =     new Botao( xp+11*45,  hp,   40,  20, corPadrao,    "pan +", 0, 0, 9);
        Botao pan2  =     new Botao( xp+10*45,  hp,   40,  20, corPadrao,    "pan -", 0, 0, 9);
        
        Botao percON   =  new Botao(xp+16*45-15, hp,   40, 20, corPercON, "perc", 1, 2, 9);
        Botao percOFF  =  new Botao(xp+16*45-15, hp,   40, 20, corPercOFF, "perc", 1, 2, 9);
        
        
        
        Botao reset  =    new Botao( 70,  70,   40, 20, corStop, "reset", 3, 0);

        TextField ins_num;
	TextField not_num;
	TextField not_hertz;
	TextField val_pan;
	TextField val_int;
        
        int largb = 80;
        int dx=largb+5;
        int dy=25;
        
        int h1 = 75;
        int x1 = 90;
        
        Botao Acoustic_Grand  = new Botao( x1+0*dx,  h1+0*dy, largb, 20, corGM, "0. Acustico",  -4, 2, 9);
        Botao Bright_Acoustic = new Botao( x1+1*dx,  h1+0*dy, largb, 20, corGM, "1. Armario",  -4, 2, 9);
        Botao Electric_Grand  = new Botao( x1+2*dx,  h1+0*dy, largb, 20, corGM, "2. Eletro-ac.",  -4, 2, 9);
        Botao Honky_Tonk      = new Botao( x1+3*dx,  h1+0*dy, largb, 20, corGM, "3. Cabaré",  -4, 2, 9);        
        Botao Electric_1      = new Botao( x1+4*dx,  h1+0*dy, largb, 20, corGM, "4. Eletr.1",  -4, 2, 9);
        Botao Electric_2      = new Botao( x1+5*dx,  h1+0*dy, largb, 20, corGM, "5. Eletr.2",  -4, 2, 9);
        Botao Harpsichord     = new Botao( x1+6*dx,  h1+0*dy, largb, 20, corGM, "6. Cravo",  -4, 2, 9);
        Botao Clavinet        = new Botao( x1+7*dx,  h1+0*dy, largb, 20, corGM, "7. Clavicórdio",  -4, 2, 9); 
        
        Botao Celesta         = new Botao( x1+0*dx,  h1+1*dy, largb, 20, corGM, "8. Celesta",  -4, 2, 9);
        Botao Glockenspiel    = new Botao( x1+1*dx,  h1+1*dy, largb, 20, corGM, "9. Glockenspiel",  -4, 2, 9);
        Botao Music_Box       = new Botao( x1+2*dx,  h1+1*dy, largb, 20, corGM, "10. Caixinha M.",  -4, 2, 9);
        Botao Vibraphone      = new Botao( x1+3*dx,  h1+1*dy, largb, 20, corGM, "11. Vibrafone",  -4, 2, 9);        
        Botao Marimba       = new Botao( x1+4*dx,  h1+1*dy, largb, 20, corGM, "12. Marimba",  -4, 2, 9);
        Botao Xylophone     = new Botao( x1+5*dx,  h1+1*dy, largb, 20, corGM, "13. Xilofone",  -4, 2, 9);
        Botao Tubular_Bells = new Botao( x1+6*dx,  h1+1*dy, largb, 20, corGM, "14. Carrilhão",  -4, 2, 9);
        Botao Dulcimer      = new Botao( x1+7*dx,  h1+1*dy, largb, 20, corGM, "15. Dulcimer",  -4, 2, 9);
        
        Botao Drawbar_Organ    = new Botao( x1+0*dx,  h1+2*dy, largb, 20, corGM, "16. Drawbar",  -4, 2, 9);
        Botao Percussive_Organ = new Botao( x1+1*dx,  h1+2*dy, largb, 20, corGM, "17. Percussivo",  -4, 2, 9);
        Botao Rock_Organ       = new Botao( x1+2*dx,  h1+2*dy, largb, 20, corGM, "18. Rock",  -4, 2, 9);
        Botao Church_Organ     = new Botao( x1+3*dx,  h1+2*dy, largb, 20, corGM, "19. Tubos",  -4, 2, 9);        
        Botao Reed_Organ       = new Botao( x1+4*dx,  h1+2*dy, largb, 20, corGM, "20. Harmônio",  -4, 2, 9);
        Botao Accordian        = new Botao( x1+5*dx,  h1+2*dy, largb, 20, corGM, "21. Acordeon",  -4, 2, 9);
        Botao Harmonica        = new Botao( x1+6*dx,  h1+2*dy, largb, 20, corGM, "22. Gaita",  -4, 2, 9);
        Botao Tango_Accordian  = new Botao( x1+7*dx,  h1+2*dy, largb, 20, corGM, "23. Bandoneon",  -4, 2, 9);
        
        
        Botao Nylon_String_Guitar   = new Botao( x1+0*dx,  h1+3*dy, largb, 20, corGM, "24. Nylon",  -4, 2, 9);
        Botao Steel_String_Guitar   = new Botao( x1+1*dx,  h1+3*dy, largb, 20, corGM, "25. Aço",  -4, 2, 9);
        Botao Electric_Jazz_Guitar  = new Botao( x1+2*dx,  h1+3*dy, largb, 20, corGM, "26. Jazz",  -4, 2, 9);
        Botao Electric_Clean_Guitar = new Botao( x1+3*dx,  h1+3*dy, largb, 20, corGM, "27. Clean",  -4, 2, 9);        
        Botao Electric_Muted_Guitar = new Botao( x1+4*dx,  h1+3*dy, largb, 20, corGM, "28. Abafado",  -4, 2, 9);
        Botao Overdriven_Guitar     = new Botao( x1+5*dx,  h1+3*dy, largb, 20, corGM, "29. Overdriven",  -4, 2, 9);
        Botao Distortion_Guitar     = new Botao( x1+6*dx,  h1+3*dy, largb, 20, corGM, "30. Dirtorcida",  -4, 2, 9);
        Botao Guitar_Harmonics      = new Botao( x1+7*dx,  h1+3*dy, largb, 20, corGM, "31. Harmonicos",  -4, 2, 9);
        
        
        Botao Acoustic_Bass       = new Botao( x1+0*dx,  h1+4*dy, largb, 20, corGM, "32. Acústico",  -4, 2, 9);
        Botao Electric_Bass_finger= new Botao( x1+1*dx,  h1+4*dy, largb, 20, corGM, "33. Elet. dedi.",  -4, 2, 9);
        Botao Electric_Bass_pick  = new Botao( x1+2*dx,  h1+4*dy, largb, 20, corGM, "34. Elet. pale.",  -4, 2, 9);
        Botao Fretless_Bass       = new Botao( x1+3*dx,  h1+4*dy, largb, 20, corGM, "35. Sem trastes",  -4, 2, 9);        
        Botao Slap_Bass_1         = new Botao( x1+4*dx,  h1+4*dy, largb, 20, corGM, "36. Ele. perc.",  -4, 2, 9);
        Botao Slap_Bass_2         = new Botao( x1+5*dx,  h1+4*dy, largb, 20, corGM, "37. Ele. perc_2",  -4, 2, 9);
        Botao Synth_Bass_1        = new Botao( x1+6*dx,  h1+4*dy, largb, 20, corGM, "38. Synth_B_1",  -4, 2, 9);
        Botao Synth_Bass_2        = new Botao( x1+7*dx,  h1+4*dy, largb, 20, corGM, "39. Synth_B_2",  -4, 2, 9);
        
          
        Botao Violin             = new Botao( x1+0*dx,  h1+5*dy, largb, 20, corGM, "40. Violino",  -4, 2, 9);
        Botao Viola              = new Botao( x1+1*dx,  h1+5*dy, largb, 20, corGM, "41. Viola",  -4, 2, 9);
        Botao Cello              = new Botao( x1+2*dx,  h1+5*dy, largb, 20, corGM, "42. Cello",  -4, 2, 9);
        Botao Contrabass         = new Botao( x1+3*dx,  h1+5*dy, largb, 20, corGM, "43. Contrabaixo",  -4, 2, 9);        
        Botao Tremolo_Strings    = new Botao( x1+4*dx,  h1+5*dy, largb, 20, corGM, "44. Tremolo",  -4, 2, 9);
        Botao Pizzicato_Strings  = new Botao( x1+5*dx,  h1+5*dy, largb, 20, corGM, "45. Pizzicato",  -4, 2, 9);
        Botao Orchestral_Strings = new Botao( x1+6*dx,  h1+5*dy, largb, 20, corGM, "46. Harpa",  -4, 2, 9);
        Botao Timpani            = new Botao( x1+7*dx,  h1+5*dy, largb, 20, corGM, "47. Timpano",  -4, 2, 9);
        
        Botao String_Ensemble_1  = new Botao( x1+0*dx,  h1+6*dy, largb, 20, corGM, "48. Cordas 1",  -4, 2, 9);
        Botao String_Ensemble_2  = new Botao( x1+1*dx,  h1+6*dy, largb, 20, corGM, "49. Cordas 2",  -4, 2, 9);
        Botao SynthStrings_1     = new Botao( x1+2*dx,  h1+6*dy, largb, 20, corGM, "50. Síntese 1",  -4, 2, 9);
        Botao SynthStrings_2     = new Botao( x1+3*dx,  h1+6*dy, largb, 20, corGM, "51. Síntese 2",  -4, 2, 9);        
        Botao Choir_Aahs         = new Botao( x1+4*dx,  h1+6*dy, largb, 20, corGM, "52. Coro",  -4, 2, 9);
        Botao Voice_Oohs         = new Botao( x1+5*dx,  h1+6*dy, largb, 20, corGM, "53. Voz",  -4, 2, 9);
        Botao Synth_Voice        = new Botao( x1+6*dx,  h1+6*dy, largb, 20, corGM, "54. Voz sint.",  -4, 2, 9);
        Botao Orchestra_Hit      = new Botao( x1+7*dx,  h1+6*dy, largb, 20, corGM, "55. Hit orq.",  -4, 2, 9);
        
        Botao Trumpet       = new Botao( x1+0*dx,  h1+7*dy, largb, 20, corGM, "56. Trumpete",  -4, 2, 9);
        Botao Trombone      = new Botao( x1+1*dx,  h1+7*dy, largb, 20, corGM, "57. Trombone",  -4, 2, 9);
        Botao Tuba          = new Botao( x1+2*dx,  h1+7*dy, largb, 20, corGM, "58. Tuba",  -4, 2, 9);
        Botao Muted_Trumpet = new Botao( x1+3*dx,  h1+7*dy, largb, 20, corGM, "59. Surdina",  -4, 2, 9);        
        Botao French_Horn   = new Botao( x1+4*dx,  h1+7*dy, largb, 20, corGM, "60. Trompa",  -4, 2, 9);
        Botao Brass_Section = new Botao( x1+5*dx,  h1+7*dy, largb, 20, corGM, "61. Metais",  -4, 2, 9);
        Botao SynthBrass_1  = new Botao( x1+6*dx,  h1+7*dy, largb, 20, corGM, "62. SynthBrs_1",  -4, 2, 9);
        Botao SynthBrass_2  = new Botao( x1+7*dx,  h1+7*dy, largb, 20, corGM, "63. SynthBrs_2",  -4, 2, 9);                
        
        Botao Soprano_Sax   = new Botao( x1+0*dx,  h1+8*dy, largb, 20, corGM, "64. Sax soprano",  -4, 2, 9);
        Botao Alto_Sax      = new Botao( x1+1*dx,  h1+8*dy, largb, 20, corGM, "65. Sax alto",  -4, 2, 9);
        Botao Tenor_Sax     = new Botao( x1+2*dx,  h1+8*dy, largb, 20, corGM, "66. Sax tenor",  -4, 2, 9);
        Botao Baritone_Sax  = new Botao( x1+3*dx,  h1+8*dy, largb, 20, corGM, "67. Sax barít.",  -4, 2, 9);        
        Botao Oboe          = new Botao( x1+4*dx,  h1+8*dy, largb, 20, corGM, "68. Oboé",  -4, 2, 9);
        Botao English_Horn  = new Botao( x1+5*dx,  h1+8*dy, largb, 20, corGM, "69. Corne inglês",  -4, 2, 9);
        Botao Bassoon       = new Botao( x1+6*dx,  h1+8*dy, largb, 20, corGM, "70. Fagote",  -4, 2, 9);
        Botao Clarinet      = new Botao( x1+7*dx,  h1+8*dy, largb, 20, corGM, "71. Clarineta",  -4, 2, 9);                
        
        Botao Piccolo      = new Botao( x1+0*dx,  h1+9*dy, largb, 20, corGM, "72. Flautim",  -4, 2, 9);
        Botao Flute        = new Botao( x1+1*dx,  h1+9*dy, largb, 20, corGM, "73. Flauta",  -4, 2, 9);
        Botao Recorder     = new Botao( x1+2*dx,  h1+9*dy, largb, 20, corGM, "74. Flauta doce",  -4, 2, 9);
        Botao Pan_Flute    = new Botao( x1+3*dx,  h1+9*dy, largb, 20, corGM, "75. Flauta Pã",  -4, 2, 9);        
        Botao Blown_Bottle = new Botao( x1+4*dx,  h1+9*dy, largb, 20, corGM, "76. Garrafa",  -4, 2, 9);
        Botao Skakuhachi   = new Botao( x1+5*dx,  h1+9*dy, largb, 20, corGM, "77. Skakuhachi",  -4, 2, 9);
        Botao Whistle      = new Botao( x1+6*dx,  h1+9*dy, largb, 20, corGM, "78. Assobio",  -4, 2, 9);
        Botao Ocarina      = new Botao( x1+7*dx,  h1+9*dy, largb, 20, corGM, "79. Ocarina",  -4, 2, 9);                
                
        Botao Lead_1_square     = new Botao( x1+0*dx,  h1+10*dy, largb, 20, corGM, "80. Quadrada",  -4, 2, 9);
        Botao Lead_2_sawtooth   = new Botao( x1+1*dx,  h1+10*dy, largb, 20, corGM, "81. DenSerra",  -4, 2, 9);
        Botao Lead_3_calliope   = new Botao( x1+2*dx,  h1+10*dy, largb, 20, corGM, "82. Calliope",  -4, 2, 9);
        Botao Lead_4_chiff      = new Botao( x1+3*dx,  h1+10*dy, largb, 20, corGM, "83. Chiff",    -4, 2, 9);        
        Botao Lead_5_charang    = new Botao( x1+4*dx,  h1+10*dy, largb, 20, corGM, "84. Charang",  -4, 2, 9);
        Botao Lead_6_voice      = new Botao( x1+5*dx,  h1+10*dy, largb, 20, corGM, "85. Voice",    -4, 2, 9);
        Botao Lead_7_fifths     = new Botao( x1+6*dx,  h1+10*dy, largb, 20, corGM, "86. Quintas",  -4, 2, 9);
        Botao Lead_8_bass_lead  = new Botao( x1+7*dx,  h1+10*dy, largb, 20, corGM, "87. Bass_lead",  -4, 2, 9);                
                
        Botao Pad_1_new_age     = new Botao( x1+0*dx,  h1+11*dy, largb, 20, corGM, "88. New_age",  -4, 2, 9);
        Botao Pad_2_warm        = new Botao( x1+1*dx,  h1+11*dy, largb, 20, corGM, "89. Morno",  -4, 2, 9);
        Botao Pad_3_polysynth   = new Botao( x1+2*dx,  h1+11*dy, largb, 20, corGM, "90. Polysynth",  -4, 2, 9);
        Botao Pad_4_choir       = new Botao( x1+3*dx,  h1+11*dy, largb, 20, corGM, "91. Choir",    -4, 2, 9);        
        Botao Pad_5_bowed       = new Botao( x1+4*dx,  h1+11*dy, largb, 20, corGM, "92. Vidr.fric.",  -4, 2, 9);
        Botao Pad_6_metallic    = new Botao( x1+5*dx,  h1+11*dy, largb, 20, corGM, "93. Metallic",    -4, 2, 9);
        Botao Pad_7_halo        = new Botao( x1+6*dx,  h1+11*dy, largb, 20, corGM, "94. Halo",  -4, 2, 9);
        Botao Pad_8_sweep       = new Botao( x1+7*dx,  h1+11*dy, largb, 20, corGM, "95. Sweep",  -4, 2, 9);                
                
        Botao FX_1_rain         = new Botao( x1+0*dx,  h1+12*dy, largb, 20, corGM, "96. Chuva gelo",  -4, 2, 9);
        Botao FX_2_soundtrack   = new Botao( x1+1*dx,  h1+12*dy, largb, 20, corGM, "97. Trilha son.",  -4, 2, 9);
        Botao FX_3_crystal      = new Botao( x1+2*dx,  h1+12*dy, largb, 20, corGM, "98. Cristal",  -4, 2, 9);
        Botao FX_4_atmosphere   = new Botao( x1+3*dx,  h1+12*dy, largb, 20, corGM, "99. Atmosfera",    -4, 2, 9);        
        Botao FX_5_brightness   = new Botao( x1+4*dx,  h1+12*dy, largb, 20, corGM, "100. Brilhos",  -4, 2, 9);
        Botao FX_6_goblins      = new Botao( x1+5*dx,  h1+12*dy, largb, 20, corGM, "101. Goblins",    -4, 2, 9);
        Botao FX_7_echoes       = new Botao( x1+6*dx,  h1+12*dy, largb, 20, corGM, "102. Ecos",  -4, 2, 9);
        Botao FX_1_sci_fi       = new Botao( x1+7*dx,  h1+12*dy, largb, 20, corGM, "103. Fic. cient.",  -4, 2, 9);                
                
        Botao Sitar        = new Botao( x1+0*dx,  h1+13*dy, largb, 20, corGM, "104. Cítara",  -4, 2, 9);
        Botao Banjo        = new Botao( x1+1*dx,  h1+13*dy, largb, 20, corGM, "105. Banjo",  -4, 2, 9);
        Botao Shamisen     = new Botao( x1+2*dx,  h1+13*dy, largb, 20, corGM, "106. Shamisen",  -4, 2, 9);
        Botao Koto         = new Botao( x1+3*dx,  h1+13*dy, largb, 20, corGM, "107. Koto",    -4, 2, 9);        
        Botao Kalimba      = new Botao( x1+4*dx,  h1+13*dy, largb, 20, corGM, "108. Kalimba",  -4, 2, 9);
        Botao Bagpipe      = new Botao( x1+5*dx,  h1+13*dy, largb, 20, corGM, "109. Gaita_foles",    -4, 2, 9);
        Botao Fiddle       = new Botao( x1+6*dx,  h1+13*dy, largb, 20, corGM, "110. Rabeca",  -4, 2, 9);
        Botao Shanai       = new Botao( x1+7*dx,  h1+13*dy, largb, 20, corGM, "111. Shanai",  -4, 2, 9);                
                                
        Botao Tinkle_Bell    = new Botao( x1+0*dx,  h1+14*dy, largb, 20, corGM, "112. Sino",  -4, 2, 9);
        Botao Agogo          = new Botao( x1+1*dx,  h1+14*dy, largb, 20, corGM, "113. Agogô",  -4, 2, 9);
        Botao Steel_Drums    = new Botao( x1+2*dx,  h1+14*dy, largb, 20, corGM, "114. Tonéis",  -4, 2, 9);
        Botao Woodblock      = new Botao( x1+3*dx,  h1+14*dy, largb, 20, corGM, "115. Madeira",    -4, 2, 9);        
        Botao Taiko_Drum     = new Botao( x1+4*dx,  h1+14*dy, largb, 20, corGM, "116. Taiko",  -4, 2, 9);
        Botao Melodic_Tom    = new Botao( x1+5*dx,  h1+14*dy, largb, 20, corGM, "117. Timbal.",    -4, 2, 9);
        Botao Synth_Drum     = new Botao( x1+6*dx,  h1+14*dy, largb, 20, corGM, "118. Timbal_s.",  -4, 2, 9);
        Botao Reverse_Cymbal = new Botao( x1+7*dx,  h1+14*dy, largb, 20, corGM, "119. Prato rev.",  -4, 2, 9);                
                
        Botao Guitar_Fret_Noise = new Botao( x1+0*dx,  h1+15*dy, largb, 20, corGM, "120. Ruido_vio.",  -4, 2, 9);
        Botao Breath_Noise      = new Botao( x1+1*dx,  h1+15*dy, largb, 20, corGM, "121. Respiração",  -4, 2, 9);
        Botao Seashore          = new Botao( x1+2*dx,  h1+15*dy, largb, 20, corGM, "122. Praia",  -4, 2, 9);
        Botao Bird_Tweet        = new Botao( x1+3*dx,  h1+15*dy, largb, 20, corGM, "123. Passarinho",    -4, 2, 9);        
        Botao Telephone_Ring    = new Botao( x1+4*dx,  h1+15*dy, largb, 20, corGM, "124. Telefone",  -4, 2, 9);
        Botao Helicopter        = new Botao( x1+5*dx,  h1+15*dy, largb, 20, corGM, "125. Helicópt.",    -4, 2, 9);
        Botao Applause          = new Botao( x1+6*dx,  h1+15*dy, largb, 20, corGM, "126. Aplausos",  -4, 2, 9);
        Botao Gunshot           = new Botao( x1+7*dx,  h1+15*dy, largb, 20, corGM, "127. Tiro",  -4, 2, 9);                
                
        Botao[] botoesGM = new Botao[128];
        Botao[] tecla    = new Botao[128];
        int largB =10;
        int largP =5;
        int altB =54;
        int altP =36;
        Color corB = Color.white;
        Color corP = Color.yellow.darker();
        

        
public Tmidi()
{     
      int x0=0; int y0=600; int offx = 20;

      for(int i=0; i<tecla.length; i++)
      { int resto  = i%12;
        int oitava = i/12;
                
        if(resto==0)  
        { x0 = offx + oitava*7*largB + 0*largB;
          tecla[i] = new Botao( x0,  y0, largB, altB, corB, "",  -4, 2, 9);                
        }
        else if(resto==2)  
        { x0 = offx + oitava*7*largB + 1*largB;
          tecla[i] = new Botao( x0,  y0, largB, altB, corB, "",  -4, 2, 9);                
        }
        else if(resto==4)  
        { x0 = offx + oitava*7*largB + 2*largB;
          tecla[i] = new Botao( x0,  y0, largB, altB, corB, "",  -4, 2, 9);                
        }
        else if(resto==5)  
        { x0 = offx + oitava*7*largB + 3*largB;
          tecla[i] = new Botao( x0,  y0, largB, altB, corB, "",  -4, 2, 9);                
        }
        else if(resto==7 )  
        { x0 = offx + oitava*7*largB + 4*largB;
          tecla[i] = new Botao( x0,  y0, largB, altB, corB, "",  -4, 2, 9);                
        }
        else if(resto==9)  
        { x0 = offx + oitava*7*largB + 5*largB;
          tecla[i] = new Botao( x0,  y0, largB, altB, corB, "",  -4, 2, 9);                
        }
        else if(resto==11 )  
        { x0 = offx + oitava*7*largB + 6*largB;
          tecla[i] = new Botao( x0,  y0, largB, altB, corB, "",  -4, 2, 9);                
        }
      }
      
      for(int i=0; i<tecla.length; i++)
      { int resto  = i%12;
        int oitava = i/12;
        
        if(resto==1)  
        { x0 = offx + oitava*7*largB + 1*largB-largP/2-1;
          tecla[i] = new Botao( x0,  y0, largP, altP, corP, "",  -4, 2, 9);                
        }
        else if(resto==3)  
        { x0 = offx + oitava*7*largB + 2*largB-largP/2-1;
          tecla[i] = new Botao( x0,  y0, largP, altP, corP, "",  -4, 2, 9);                
        }
        else if(resto==6)  
        { x0 = offx + oitava*7*largB + 4*largB-largP/2-1;
          tecla[i] = new Botao( x0,  y0, largP, altP, corP, "",  -4, 2, 9);                
        }
        else if(resto==8)  
        { x0 = offx + oitava*7*largB + 5*largB-largP/2-1;
          tecla[i] = new Botao( x0,  y0, largP, altP, corP, "",  -4, 2, 9);                
        }
        else if(resto==10 )  
        { x0 = offx + oitava*7*largB + 6*largB-largP/2-1;
          tecla[i] = new Botao( x0,  y0, largP, altP, corP, "",  -4, 2, 9);                
        }
      }

          
      
    
      botoesGM[0]=Acoustic_Grand;
      botoesGM[1]=Bright_Acoustic;
      botoesGM[2]=Electric_Grand;
      botoesGM[3]=Honky_Tonk;
      botoesGM[4]=Electric_1;
      botoesGM[5]=Electric_2;
      botoesGM[6]=Harpsichord;
      botoesGM[7]=Clavinet;
    
      botoesGM[8] =Celesta;
      botoesGM[9] =Glockenspiel;
      botoesGM[10]=Music_Box;
      botoesGM[11]=Vibraphone;
      botoesGM[12]=Marimba;
      botoesGM[13]=Xylophone;
      botoesGM[14]=Tubular_Bells;
      botoesGM[15]=Dulcimer;
    
      botoesGM[16]=Drawbar_Organ;
      botoesGM[17]=Percussive_Organ;
      botoesGM[18]=Rock_Organ;
      botoesGM[19]=Church_Organ;
      botoesGM[20]=Reed_Organ;
      botoesGM[21]=Accordian;
      botoesGM[22]=Harmonica;
      botoesGM[23]=Tango_Accordian;
    
      botoesGM[24]=Nylon_String_Guitar;
      botoesGM[25]=Steel_String_Guitar;
      botoesGM[26]=Electric_Jazz_Guitar;
      botoesGM[27]=Electric_Clean_Guitar;
      botoesGM[28]=Electric_Muted_Guitar;
      botoesGM[29]=Overdriven_Guitar;
      botoesGM[30]=Distortion_Guitar;
      botoesGM[31]=Guitar_Harmonics;
             
      botoesGM[32]=Acoustic_Bass;
      botoesGM[33]=Electric_Bass_finger;
      botoesGM[34]=Electric_Bass_pick;
      botoesGM[35]=Fretless_Bass;
      botoesGM[36]=Slap_Bass_1;
      botoesGM[37]=Slap_Bass_2;
      botoesGM[38]=Synth_Bass_1;
      botoesGM[39]=Synth_Bass_2;
                  
      botoesGM[40]=Violin;
      botoesGM[41]=Viola;
      botoesGM[42]=Cello;
      botoesGM[43]=Contrabass;
      botoesGM[44]=Tremolo_Strings;
      botoesGM[45]=Pizzicato_Strings;
      botoesGM[46]=Orchestral_Strings;
      botoesGM[47]=Timpani;
      
      botoesGM[48]=String_Ensemble_1;
      botoesGM[49]=String_Ensemble_2;
      botoesGM[50]=SynthStrings_1;
      botoesGM[51]=SynthStrings_2;
      botoesGM[52]=Choir_Aahs;
      botoesGM[53]=Voice_Oohs;
      botoesGM[54]=Synth_Voice;
      botoesGM[55]=Orchestra_Hit;
                  
      botoesGM[56]=Trumpet;
      botoesGM[57]=Trombone;
      botoesGM[58]=Tuba;
      botoesGM[59]=Muted_Trumpet;
      botoesGM[60]=French_Horn;
      botoesGM[61]=Brass_Section;
      botoesGM[62]=SynthBrass_1;
      botoesGM[63]=SynthBrass_2;
                  
      botoesGM[64]=Soprano_Sax;
      botoesGM[65]=Alto_Sax;
      botoesGM[66]=Tenor_Sax;
      botoesGM[67]=Baritone_Sax;
      botoesGM[68]=Oboe;
      botoesGM[69]=English_Horn;
      botoesGM[70]=Bassoon;
      botoesGM[71]=Clarinet;
                  
      botoesGM[72]=Piccolo;
      botoesGM[73]=Flute;
      botoesGM[74]=Recorder;
      botoesGM[75]=Pan_Flute;
      botoesGM[76]=Blown_Bottle;
      botoesGM[77]=Skakuhachi;
      botoesGM[78]=Whistle;
      botoesGM[79]=Ocarina;
                  
      botoesGM[80]=Lead_1_square;
      botoesGM[81]=Lead_2_sawtooth;
      botoesGM[82]=Lead_3_calliope;
      botoesGM[83]=Lead_4_chiff;
      botoesGM[84]=Lead_5_charang;
      botoesGM[85]=Lead_6_voice;
      botoesGM[86]=Lead_7_fifths;
      botoesGM[87]=Lead_8_bass_lead;
                  
      botoesGM[88]=Pad_1_new_age;
      botoesGM[89]=Pad_2_warm;
      botoesGM[90]=Pad_3_polysynth;
      botoesGM[91]=Pad_4_choir;
      botoesGM[92]=Pad_5_bowed;
      botoesGM[93]=Pad_6_metallic;
      botoesGM[94]=Pad_7_halo;
      botoesGM[95]=Pad_8_sweep;
                  
      botoesGM[96]=FX_1_rain;
      botoesGM[97]=FX_2_soundtrack;
      botoesGM[98]=FX_3_crystal;
      botoesGM[99]=FX_4_atmosphere;
      botoesGM[100]=FX_5_brightness;
      botoesGM[101]=FX_6_goblins;
      botoesGM[102]=FX_7_echoes;
      botoesGM[103]=FX_1_sci_fi;
                  
      botoesGM[104]=Sitar;
      botoesGM[105]=Banjo;
      botoesGM[106]=Shamisen;
      botoesGM[107]=Koto;
      botoesGM[108]=Kalimba;
      botoesGM[109]=Bagpipe;
      botoesGM[110]=Fiddle;
      botoesGM[111]=Shanai;
                  
      botoesGM[112]=Tinkle_Bell;
      botoesGM[113]=Agogo;
      botoesGM[114]=Steel_Drums;
      botoesGM[115]=Woodblock;
      botoesGM[116]=Taiko_Drum;
      botoesGM[117]=Melodic_Tom;
      botoesGM[118]=Synth_Drum;
      botoesGM[119]=Reverse_Cymbal;
                  
      botoesGM[120]=Guitar_Fret_Noise;
      botoesGM[121]=Breath_Noise;
      botoesGM[122]=Seashore;
      botoesGM[123]=Bird_Tweet;
      botoesGM[124]=Telephone_Ring;
      botoesGM[125]=Helicopter;
      botoesGM[126]=Applause;
      botoesGM[127]=Gunshot;
                  
                 
      oM   = new MidiJS();
      oM.reset(canal);
      oM.bank_select(0, canal);
      // oM.generalMIDIon();
      oM.program_change(canal, instrumento);                                                                                      
      // oM.panA(pan);                                                                                      
      oM.pan(pan, canal);                                                                                      
      ins_num =new TextField(4);
      not_num =new TextField(4);
      not_hertz =new TextField(12);
      val_pan =new TextField(4);
      val_int =new TextField(4);
      add(ins_num);
      add(not_num);
      add(not_hertz);
      add(val_pan);
      add(val_int);
      ins_num.setText(""+instrumento);
      not_num.setText(""+nota);
      not_hertz.setText(toHerz(nota));                                              
      val_pan.setText(""+pan);
      val_int.setText(""+veloc);
      setBackground(new Color(255,255,255));
      setFont(new Font("Helvetica", Font.PLAIN, 10));
      this.resize(largura+25, altura+50);
      this.show();
 }


public void init()
{ Tmidi hipernota;
  hipernota = new Tmidi();
}

        public boolean mouseDown(Event evt, int x, int y)
        {                         
          Graphics ga = getGraphics();
            
               if (play1.dentroRetangulo(x,y)) play1.apertaBotao(ga);
          //else if (play2.dentroRetangulo(x,y)) play2.apertaBotao(ga);
          else if (play3.dentroRetangulo(x,y)) play3.apertaBotao(ga);
          else if (percON.dentroRetangulo(x,y)) percON.apertaBotao(ga);
          else if (percOFF.dentroRetangulo(x,y)) percOFF.apertaBotao(ga);
          else if (ins1.dentroRetangulo(x,y)) ins1.apertaBotao(ga);
          else if (ins2.dentroRetangulo(x,y)) ins2.apertaBotao(ga);
          else if (pan1.dentroRetangulo(x,y)) pan1.apertaBotao(ga);
          else if (pan2.dentroRetangulo(x,y)) pan2.apertaBotao(ga);
          else if (intens1.dentroRetangulo(x,y)) intens1.apertaBotao(ga);
          else if (intens2.dentroRetangulo(x,y)) intens2.apertaBotao(ga);
          else if (stop.dentroRetangulo(x,y))   stop.apertaBotao(ga);
          
          
          else for(int i=0; i<botoesGM.length; i++)
          { if (botoesGM[i].dentroRetangulo(x,y)) { botoesGM[i].apertaBotao(ga);            
                                                    return true;
                                                  }
          }
                    
          
          for(int i=0; i<tecla.length; i++)
          { 
            int resto = i%12;
            if(resto==1 || resto==3 || resto==6 || resto==8 || resto==10)     
            { if (tecla[i].dentroRetangulo(x,y)) { 
                                              stop.apagaBotao(ga);
                                              tecla[i].apertaBotao(ga);
                                              oM.note_off(i, veloc, canal);                                                                                   
	                                      not_num.setText(new Integer(i).toString());                                              
	                                      not_hertz.setText(toHerz(i));                                              
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(i, veloc, canal);      
                                              nota = i;
                                              
                                              escreve_comando(ga, 1, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 2, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 3, "note_on("+nota+", "+veloc+", "+canal+")");                                              
                                              
                                                    return true;
                                                  }
            }
          }
          
          
          for(int i=0; i<tecla.length; i++)
          { 
            int resto = i%12;
            if(resto==0 || resto==2 || resto==4 || resto==5 || resto==7 || resto==9 || resto==11)     
            { if (tecla[i].dentroRetangulo(x,y)) { 
		                                              stop.apagaBotao(ga);
		                                              tecla[i].apertaBotao(ga);
		                                              oM.note_off(i, veloc, canal);                                                                                   
					                                     not_num.setText(new Integer(i).toString());                                              
					                                     not_hertz.setText(toHerz(i));                                              
		
		                                              oM.notes_off_canal(canal);
		                                              oM.program_change(instrumento, canal); 
		                                              oM.note_on(i, veloc, canal);                          
		                                              nota = i;
		                                              escreve_comando(ga, 1, "notes_off_canal("+canal+")");
		                                              escreve_comando(ga, 2, "program_change("+instrumento+", "+canal+")");
		                                              escreve_comando(ga, 3, "note_on("+nota+", "+veloc+", "+canal+")");                                              
                                              
                                                    return true;                                                    
                                                  }
            }
          }                              
          
          return true;
        }

        private String toHerz(int n)
        { double f = 8.17579*Math.pow(2, n/12.0);
          if(percussao) return "";
          else          return reformata(f, 3)+" Hz";
        }
        
        public String reformata(double x, int casas)
        { DecimalFormat df = new DecimalFormat (  ) ; 
          df.setMaximumFractionDigits(casas);
          return df.format(x);
        }
                    
        private void escreve_comando(Graphics g, int linha, String s)
        { int x=30;
          int y=510;
          int ddy = 15;
          int larg=700;
          int altu=78;
                    
          if(linha==1) 
          { g.setColor(this.corFrente);
            g.fillRect(x, y, larg, altu);
          }

          g.setColor(Cores.corLetra1);
          g.drawString("COMANDOS MIDI:", x, y+ddy);
          
          g.setColor(Cores.corLetra1);
          g.drawString(s, x+35, y+(linha+1)*ddy);
        }
        
        public boolean mouseUp(Event evt, int x, int y)
        { Graphics ga = getGraphics();
          if (play1.dentroRetangulo(x,y))
                                            {
                                              stop.apagaBotao(ga);
                                              //play2.apagaBotao(ga);
                                              play3.apagaBotao(ga);
                                              play1.acendeBotao(ga);
                                              oM.note_off(nota, veloc, canal);                                                                                   
                                              nota++;
	                                           not_num.setText(new Integer(nota).toString());                                              
	                                           not_hertz.setText(toHerz(nota));                                              
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(nota, veloc, canal);                                                    
                                              
                                              escreve_comando(ga, 1, "note_off("+nota+", "+veloc+", "+canal+")");
                                              escreve_comando(ga, 2, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 3, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 4, "note_on("+nota+", "+veloc+", "+canal+")");
                                              
                                             }

          else if (play3.dentroRetangulo(x,y)) 
                                                 {
                                              stop.apagaBotao(ga);
                                              play1.apagaBotao(ga);
                                              //play2.apagaBotao(ga);
                                              play3.acendeBotao(ga);
                                              oM.note_off(nota, veloc, canal);                                              
                                              nota--;
	                                           not_num.setText(new Integer(nota).toString());                                              
	                                           not_hertz.setText(toHerz(nota));                                              
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(nota, veloc, canal);                                                    
                                              
                                              escreve_comando(ga, 1, "note_off("+nota+", "+veloc+", "+canal+")");
                                              escreve_comando(ga, 2, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 3, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 4, "note_on("+nota+", "+veloc+", "+canal+")");
                                              
                                              
                                                  }

          else if (percON.dentroRetangulo(x,y)||percOFF.dentroRetangulo(x,y)) 
                                                 {
                                              percussao=!percussao;
                                              if(percussao) { percON.pintaBotao(ga);                                                              
                                                              percON.acendeBotao(ga);                                                              
                                                              canal=9;
                                                            }
                                                       else { percOFF.pintaBotao(ga);                                                              
                                                              percOFF.apagaBotao(ga);                                                              
                                                              canal=0;
                                                            }
                                                  }
          else if (ins1.dentroRetangulo(x,y)) 
                                                 {                                       
                                              ins1.apagaBotao(ga);
                                              instrumento++;                                              
	                                          ins_num.setText(new Integer(instrumento).toString());                                              
                                              oM.program_change(instrumento, canal); 
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(nota, veloc, canal);        
                                                                                            
                                              escreve_comando(ga, 1, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 2, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 3, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 4, "note_on("+nota+", "+veloc+", "+canal+")");
                                                                                            
                                                  }
          else if (ins2.dentroRetangulo(x,y)) 
                                                 {                                       
                                              ins2.apagaBotao(ga);
                                              instrumento--;
	                                          ins_num.setText(new Integer(instrumento).toString());                                              
                                              oM.program_change(instrumento, canal);      
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(nota, veloc, canal);                                                    
                                              
                                              escreve_comando(ga, 1, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 2, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 3, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 4, "note_on("+nota+", "+veloc+", "+canal+")");
                                              
                                                 }
          else if (pan1.dentroRetangulo(x,y)) 
                                                 {
                                              pan1.apagaBotao(ga);                                               
                                              pan=pan+5; if(pan>127)pan=127;
	                                          val_pan.setText(new Integer(pan).toString());                                              
                                              //oM.panA(pan);                                                                                
                                              oM.pan(pan, canal);         
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(nota, veloc, canal);                                                    
                                              
                                              escreve_comando(ga, 1, "pan("+pan+", "+canal+")");
                                              escreve_comando(ga, 2, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 3, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 4, "note_on("+nota+", "+veloc+", "+canal+")");                                                                                            
                                                 }
          else if (pan2.dentroRetangulo(x,y)) 
                                                 {
                                              pan2.apagaBotao(ga);
                                              pan=pan-5; if(pan<0)pan=0;
	                                          val_pan.setText(new Integer(pan).toString());                                              
                                              //oM.panA(pan);                                                                                
                                              oM.pan(pan, canal);        
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(nota, veloc, canal);                                                    
                                              
                                              escreve_comando(ga, 1, "pan("+pan+", "+canal+")");
                                              escreve_comando(ga, 2, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 3, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 4, "note_on("+nota+", "+veloc+", "+canal+")");
                                              
                                              
                                                 }
          else if (intens1.dentroRetangulo(x,y)) 
                                                 {
                                              intens1.apagaBotao(ga);
                                              veloc=veloc+5; if(veloc>127)veloc=127;
	                                      val_int.setText(new Integer(veloc).toString());    
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(nota, veloc, canal);                                                    
                                                  
                                              escreve_comando(ga, 1, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 2, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 3, "note_on("+nota+", "+veloc+", "+canal+")");
                                              
                                                 }
          else if (intens2.dentroRetangulo(x,y)) 
                                                 {
                                              intens2.apagaBotao(ga);
                                              veloc=veloc-5; if(veloc<0)veloc=0;
	                                          val_int.setText(new Integer(veloc).toString());     
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(nota, veloc, canal);                                                    

                                              escreve_comando(ga, 1, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 2, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 3, "note_on("+nota+", "+veloc+", "+canal+")");                                              
                                              
                                                  }
          else if (stop.dentroRetangulo(x,y))   {
                                              play1.apagaBotao(ga);
                                              stop.acendeBotao(ga);
                                              oM.notes_off_canal(canal);
                                              
                                              escreve_comando(ga, 1, "notes_off_canal("+canal+")");                                              
                                                 }

          
          else for(int i=0; i<botoesGM.length; i++)
          { if (botoesGM[i].dentroRetangulo(x,y)) { 
                
                                              stop.apagaBotao(ga);                
                                              apagaBotoesGM(ga);
                                              botoesGM[i].acendeBotao(ga);   

                                              percussao=false;
                                              canal=0;
                                              percOFF.pintaBotao(ga);                                                              
                                              percOFF.apagaBotao(ga);                                                                  
                                              instrumento = i;
                                              oM.notes_off_canal(canal);
                                              oM.program_change(instrumento, canal); 
                                              oM.note_on(nota, veloc, canal);     
                                              
                                              escreve_comando(ga, 1, "notes_off_canal("+canal+")");
                                              escreve_comando(ga, 2, "program_change("+instrumento+", "+canal+")");
                                              escreve_comando(ga, 3, "note_on("+nota+", "+veloc+", "+canal+")");                                              
                                              
                                                    return true;
                                                  }
          }
                              
          for(int i=0; i<tecla.length; i++)
          { 
            int resto = i%12;
            if(resto==1 || resto==3 || resto==6 || resto==8 || resto==10)     
            { if (tecla[i].dentroRetangulo(x,y)) { 
                                              pintaTeclado(ga);                                              
                                                    return true;
                                                  }
            }
          }
          
          
          for(int i=0; i<tecla.length; i++)
          { 
            int resto = i%12;
            if(resto==0 || resto==2 || resto==4 || resto==5 || resto==7 || resto==9 || resto==11)     
            { if (tecla[i].dentroRetangulo(x,y)) {         
                                              pintaTeclado(ga);                                              
                                                    return true;
                                                  }
            }
          }          
                                                                    
          return true;
        }


 public void paint(Graphics     g)
 {
      bansom.pintaBotao(g, 12, "Tmidi", 20,48, true);
      g.setColor(Cores.corLetra1);
      g.setFont(new Font("Helvetica", Font.PLAIN, 9));                  
      g.drawString("Pianos", x1-70, h1+1*dy-10);       
      g.drawString("Perc. cromática", x1-70, h1+2*dy-10);       
      g.drawString("Órgãos", x1-70, h1+3*dy-10);       
      g.drawString("Violão", x1-70, h1+4*dy-10);       
      g.drawString("Baixos", x1-70, h1+5*dy-10);       
      g.drawString("Cordas", x1-70, h1+6*dy-10);       
      g.drawString("Sinfônica", x1-70, h1+7*dy-10);       
      g.drawString("Metais", x1-70, h1+8*dy-10);       
      g.drawString("Palhetas", x1-70, h1+9*dy-10);       
      g.drawString("Flautas", x1-70, h1+10*dy-10);       
      g.drawString("Solos sint.", x1-70, h1+11*dy-10);       
      g.drawString("Fundos sint.", x1-70, h1+12*dy-10);       
      g.drawString("Efeitos sint.", x1-70, h1+13*dy-10);       
      g.drawString("Étnicos", x1-70, h1+14*dy-10);       
      g.drawString("Percussão", x1-70, h1+15*dy-10);       
      g.drawString("Sonoplastia", x1-70, h1+16*dy-10);
      
      g.drawString("2000-2008 A. Arcela", 664, 48);
      g.drawString("Universidade de Brasília", 650, 58);
      
          play1.pintaBotao(g);
          play3.pintaBotao(g);
          percOFF.pintaBotao(g);
          ins1.pintaBotao(g);
          ins2.pintaBotao(g);
          pan1.pintaBotao(g);
          pan2.pintaBotao(g);
          intens1.pintaBotao(g);
          intens2.pintaBotao(g);
          stop.pintaBotao(g);

			 ins_num.reshape(xp+6*45, hp, 30, 20);
			 not_num.reshape(xp+3*45, hp, 30, 20);
			 not_hertz.reshape(xp+13*45, hp, 75, 20);
			 val_pan.reshape(xp+12*45, hp, 30, 20);
			 val_int.reshape(xp+9*45, hp, 30, 20);   
          
		    for(int i=0; i<botoesGM.length; i++) botoesGM[i].pintaBotao(g);                    
		    pintaTeclado(g);
 }
  
 private void pintaTeclado(Graphics g)
 { 
          for(int i=0; i<tecla.length; i++) 
          { int resto  = i%12;
            if(resto==0 || resto==2 || resto==4 || resto==5 || resto==7 || resto==9 || resto==11)                
            { tecla[i].pintaBotao(g); }
          }
          for(int i=0; i<tecla.length; i++) 
          { int resto  = i%12;
            if(resto==1 || resto==3 || resto==6 || resto==8 || resto==10)                
            { tecla[i].pintaBotao(g); }
          }

 } 
 
 
 private void apagaBotoesGM(Graphics g)
 { for(int i=0; i<botoesGM.length; i++) botoesGM[i].apagaBotao(g);
 }

} //-- fim da classe Tmidi


//--- 21/04/2008 







