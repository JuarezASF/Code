import java.awt.Event;
import java.io.*;

/**
 * @author Aluizio Arcela
 * @version 0.6 [06/03/99]
 *
 * 
 *     .......
 *     Midi.java
 *     ^^^^^^^
 *
 * --- Laboratório de Ciência da Música       --- *
 * --- Departamento de Ciência da Computação  --- *
 * --- Universidade de Brasília               --- *
 * --- Brasília, DF 70910-900                 --- *
 *
 * 

 */

class Midi
{ File             drvmidi;
  FileOutputStream nomedrv;
  DataOutputStream mid;

  int    instr,
         dur_ms,
         tecla,
         veloc,
         orto,
         kanal;
  
  int    pan=64;

Midi()
{
    try
    { drvmidi  = new File("midixxx0");
      nomedrv  = new FileOutputStream(drvmidi);
      mid      = new DataOutputStream(nomedrv);
    }
    catch (IOException e) {}
}

void toca(int instr, int dur_ms, int tecla, int lsb, int msb, int p1, int p2, int p3, int p4, int orto, int kanal)
{
  int panxy,
      veloc  = p1+p2+p3+p4;  //--depois distribuir aos 4 canais do plano o
  try
  {
    mid.writeByte(kanal+192);         //------program change
    mid.writeByte(instr);             //------numero do instrumento general midi

    if (orto==0) panxy=0; else panxy=127;

    mid.writeByte(kanal+176);         //-----mensagem do tipo control change
    mid.writeByte(10);                //-----controlador midi no. 10 (pan)
    mid.writeByte(panxy);

    mid.writeByte(kanal+144);         //note-on
    mid.writeByte(tecla);             //tecla midi
    mid.writeByte(veloc);             //veloc midi

    pitch_bend(lsb, msb, kanal);
    mid.flush();
  }
  catch (IOException e) {}
}


void note_on(int kanal, int tecla, int veloc)
{ try
  {         
    mid.writeByte(kanal+144);         //note-on
    mid.writeByte(tecla);             //tec midi
    mid.writeByte(veloc);             //vel midi
    
    mid.writeByte(kanal+176);         //-----mensagem do tipo control change
    mid.writeByte(10);                //-----controlador midi no. 10 (pan)
    mid.writeByte(pan);
        
    mid.flush();
  }
  catch (IOException e) {}
}


void program_change(int kanal, int instr)
{ try
  {
    mid.writeByte(kanal+192);         //------program change
    mid.writeByte(instr);             //------numero do instrumento general midi
    mid.flush();
  }
  catch (IOException e) {}
}


void note_off(int kanal, int tecla, int veloc)
{ try
  { mid.writeByte(kanal+128);         //note-off
    mid.writeByte(tecla);             //tec midi
    mid.writeByte(veloc);             //vel midi
    mid.flush();
  }
  catch (IOException e) {}
}

void pan(int kanal, int p)
{ try
   {mid.writeByte(kanal+176);         //-----mensagem do tipo control change
    mid.writeByte(10);                //-----controlador midi no. 10 (pan)
    mid.writeByte(p);
    mid.flush();
  }
  catch (IOException e) {}
}
void panA(int p)
{ pan = p;
}

void reset()
{ try
   {mid.writeByte(kanal+176);         //-----mensagem do tipo control change
    mid.writeByte(121);               //-----controlador midi no. 121 (Reset all Controllers)
    mid.writeByte(0);
    mid.flush();
  }
  catch (IOException e) {}
}

void note_off(int kanal, int tecla, int pesq, int pdir)
{ try
  { mid.writeByte(kanal+128);         //note-off
    mid.writeByte(tecla);             //tec midi
    mid.writeByte(pesq);              //vel midi

    mid.writeByte(kanal+128);         //note-off
    mid.writeByte(tecla);             //tec midi
    mid.writeByte(pdir);              //vel midi
    mid.flush();
  }
  catch (IOException e) {}
}


void notes_off_canal(int canal_m)
{ try
  { mid.writeByte(canal_m+176);
    mid.writeByte(123);
    mid.writeByte(0);
    mid.flush();
  }
  catch (IOException e) {}
}

void notes_off_geral()
{ for (int i=0; i<15; i++)
   this.notes_off_canal(i);
}

void volume_canal(int vol)
{ try
  { mid.writeByte(kanal+176);  //-----mensagem do tipo control change
    mid.writeByte(7);          //-----controlador midi no. 7 (main volume)
    mid.writeByte(vol);
    mid.flush();
  }
  catch (IOException e) {}
}

void bank_select(int banco, int canal)
{ try
  {
    mid.writeByte(canal+176); //-----mensagem do tipo control change
    mid.writeByte(0);         //-----controlador midi no. 0 (bank select)
    mid.writeByte(banco);
    mid.flush();
  }
  catch (IOException e) {}
}

void pitch_bend(int lsb, int msb, int canal)
{ try
  {
    mid.writeByte(canal+224);
    mid.writeByte(lsb);
    mid.writeByte(msb);
    mid.flush();
  }
  catch (IOException e) {}
}

void ataque(int valor)        //---arquitetura da AWE64 nao responde
{ try
  { mid.writeByte(kanal+176); //-----mensagem do tipo control change
    mid.writeByte(73);        //-----controlador midi no. 73 (attack time)
    mid.writeByte(valor);
    mid.flush();
  }
  catch (IOException e) {}
}


void generalMIDIon()
{ try
  { mid.writeByte(kanal+240);  //--- F0 : Status for system exclusive message
    mid.writeByte(126);        //--- 7E
    mid.writeByte(127);        //--- 7F
    mid.writeByte(9);          //--- 09
    mid.writeByte(1);          //--- 01 : General Midi on
    mid.writeByte(247);        //--- EOX: End of system exclusive
    mid.flush();
  }
  catch (IOException e) {}
}


void generalMIDIoff()
{ try
  { mid.writeByte(kanal+240);  //--- F0 : Status for system exclusive message
    mid.writeByte(126);        //--- 7E
    mid.writeByte(127);        //--- 7F
    mid.writeByte(9);          //--- 09
    mid.writeByte(2);          //--- 02 : General Midi off
    mid.writeByte(247);        //--- EOX: End of system exclusive
    mid.flush();
  }
  catch (IOException e) {}
}


} //--- fim da classe Midi