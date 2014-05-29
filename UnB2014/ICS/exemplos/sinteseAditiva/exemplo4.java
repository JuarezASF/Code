import sintese.*;


public class E13d
{  Curva   curva1, curva2, curva3;      
   Envoltoria   env1   = new Envoltoria();   
   Envoltoria   env2   = new Envoltoria();   
   Envoltoria   env3   = new Envoltoria();   
   UnidadeH     uh1    = new UnidadeH();
   UnidadeH     uh2    = new UnidadeH();
   UnidadeH     uh3    = new UnidadeH();
   InstrumentoAditivo ins;   
   
   public E13d()
   { curva1 = new Curva(720);     
     curva1.addPonto(0f, 0f);
     curva1.addPonto(30f, 1000f);
     curva1.addPonto(200f, 300f);
     curva1.addPonto(720f, 0f);

     curva2 = new Curva(720);     
     curva2.addPonto(0f, 0f);
     curva2.addPonto(20f, 400f);
     curva2.addPonto(240f, 300f);
     curva2.addPonto(720f, 0f);

     curva3 = new Curva(720);     
     curva3.addPonto(0f, 0f);
     curva3.addPonto(10f,  300f);
     //curva3.addPonto(280f, 200f);
     curva3.addPonto(720f, 0f);

     env1.setCURVA(curva1);
     env2.setCURVA(curva2);
     env3.setCURVA(curva2);
  
     uh1.setEnvoltoria(env1);
     uh1.setH(1);
     uh1.setLambda(0.5f);
     uh1.setFase(90f);
     uh1.setGanho(4);

     uh2.setEnvoltoria(env2);
     uh2.setH(2);
     uh2.setLambda(0.5f);
     uh2.setFase(0f);
     uh2.setGanho(4);
     
     uh3.setEnvoltoria(env3);
     uh3.setH(3);
     uh3.setLambda(0.5f);
     uh3.setFase(120f);
     uh3.setGanho(4);

     ins = new InstrumentoAditivo();
     
     ins.addUnidade(uh1);
     ins.addUnidade(uh2);
     ins.addUnidade(uh3);

    float f1 = 150;
    float f2 = f1*5/4f;
    float f3 = f1*3/2f;
    float f4 = f1*2/1f;

    Nota n1 = new Nota(0.25f, f1, 10);
    Nota n2 = new Nota(0.50f, f2, 12);
    Nota n3 = new Nota(0.25f, f3, 15);
    Nota n4 = new Nota(0.75f, f4, 15);


    Melodia mel1 = new Melodia();
    mel1.addNota(n1);
    mel1.addNota(n2);
    mel1.addNota(n3);
    mel1.addNota(n4);
 
    Som som1 = mel1.getSom(ins);
    som1.visualiza();

    try{ System.in.read();
          System.exit(0);
        }
     catch(Exception e){};

   }
      
   public static void main(String args[])
   { new E13d();
   }   

}
