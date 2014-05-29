import sintese.*;

class E13a  
{  Curva      curva1, curva2, curva3;      
   Envoltoria   env1   = new Envoltoria();   
   Envoltoria   env2   = new Envoltoria();   
   Oscilador o1;
      
   public E13a()
   { curva1 = new Curva(720);//720 define o tamanho da tabela     
     curva1.addPonto(  0f, 1000f);
     curva1.addPonto(720f, 1000f);

     curva2 = new Curva(720);     
     curva2.addPonto(0f, 20f);
     curva2.addPonto(720f, 220f);     

     env1.setCURVA(curva1);      
     env1.setGanho(2f);

     env2.setCURVA(curva2);    
     env2.setGanho(2f);   

     o1 = new Oscilador(env1, env2); 
     /*a primeira envoltório determina a amplitude;
     a segunda determina a frequência*/ 
     
     Som som = new Som(o1, 54, "fm");
     /* o segundo argumento define a duração e o terceiro dá um nome ao SOM*/
     som.salvawave();
     som.tocawave();

   }
      
   public static void main(String args[])
   { new E13a();
   }   
}