import sintese.*;

public class E13f
{  Curva        curva1, curva2, curva3;
   Envoltoria   env1   = new Envoltoria();
   Envoltoria   env2   = new Envoltoria();
   Envoltoria   env3   = new Envoltoria();
   UnidadeH     uh1    = new UnidadeH();
   UnidadeH     uh2    = new UnidadeH();
   UnidadeH     uh3    = new UnidadeH();
   InstrumentoAditivo ins;

   public E13f()
   { curva1 = new Curva(720);
     curva1.addPonto(0f, 0f);
     curva1.addPonto(30f, 1000f);
     curva1.addPonto(600f, 300f);
     curva1.addPonto(720f, 0f);

     curva2 = new Curva(720);
     curva2.addPonto(0f, 0f);
     curva2.addPonto(20f, 400f);
     curva2.addPonto(540f, 300f);
     curva2.addPonto(720f, 0f);

     curva3 = new Curva(720);
     curva3.addPonto(0f, 0f);
     curva3.addPonto(10f,  300f);
     curva3.addPonto(480f, 200f);
     curva3.addPonto(720f, 0f);

     env1.setCURVA(curva1);
     env2.setCURVA(curva2);
     env3.setCURVA(curva2);

     uh1.setEnvoltoria(env1);
     uh1.setH(1);
     uh1.setLambda(0.5f);
     uh1.setFase(90f);

     uh2.setEnvoltoria(env2);
     uh2.setH(2);
     uh2.setLambda(0.5f);
     uh2.setFase(0f);

     uh3.setEnvoltoria(env3);
     uh3.setH(3);
     uh3.setLambda(0.5f);
     uh3.setFase(120f);

     ins = new InstrumentoAditivo();
     ins.addUnidade(uh1);
     ins.addUnidade(uh2);
     ins.addUnidade(uh3);
     ins.setGanho(4);

     Melodia m1 = Tema.tema_bwv988goldberg_v03_eq(0.85f).transposicao(0.35f);
     m1.print();

     Som s1 = m1.getSom(ins);
     //s1.salvawave();
     //s1.tocawave();
     
     s1.visualiza();

     try{ System.in.read();
          System.exit(0);
        }
     catch(Exception e){};

   }
     

   
   public static void main(String args[])
   { new E13f();
   }   

}