import sintese.*;

class E13b
{  Curva        curva1, curva2, curva3;
   Envoltoria   env1   = new Envoltoria();   
   Envoltoria   env2   = new Envoltoria();   
   Envoltoria   env3   = new Envoltoria();   

   Oscilador o1, o2;
   Somador   somador;
   
   public E13b()
   {      
     curva1 = new Curva(720);     
     curva1.addPonto(  0f, 2000f);
     curva1.addPonto(720f, 0f);
     //curva1.addPonto(  0f, 2000f);
     //curva1.addPonto(720f, 2000f);

     curva2 = new Curva(720);     
     curva2.addPonto(0f, 0f);
     curva2.addPonto(30f, 1000f);
     curva2.addPonto(600f, 300f);
     curva2.addPonto(720f, 0f);     

     curva3 = new Curva(720);     
     curva3.addPonto(  0f, 200f);
     curva3.addPonto(720f, 200f);

     env1.setCURVA(curva1);      
     env2.setCURVA(curva2);    
     env3.setCURVA(curva3);    

     env2.setGanho(3);

     o2 = new Oscilador(env1);
     o2.setFrequencia(180);
     somador = new Somador(env3, o2);

     o1 = new Oscilador(env2, somador);

     Som som = new Som(o1, 5f, "fm_dx7.wav");
     som.salvawave();
     som.tocawave();

     //SomVolante sv = new SomVolante(o1, 4f);
     //sv.toca();
   }
   
   
  public static void main(String args[])
  { new E13b();
  }

}
