import sintese.*;

public class E13e
{  Curva        curva1, curva2, curva3;
   Envoltoria   env1   = new Envoltoria();
   Envoltoria   env2   = new Envoltoria();
   Envoltoria   env3   = new Envoltoria();
   UnidadeH     uh1    = new UnidadeH();
   UnidadeH     uh2    = new UnidadeH();
   UnidadeH     uh3    = new UnidadeH();
   InstrumentoAditivo insA;
   InstrumentoAditivo insFM;


   public E13e()
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

     insA = new InstrumentoAditivo();
     insA.addUnidade(uh1);
     insA.addUnidade(uh2);
     insA.addUnidade(uh3);

     insA.setGanho(14);
     

     //Melodia m2 = Escala.hirajoshi(120);
     //Melodia m2 = Escala.diatonicaMaiorTemperada();
     Melodia m2 = Escala.diatonicaMaiorJusta(110);
     m2.print();

     Som s2 = m2.getSom(insA);
     //Som s2 = m2.getSom(new InstrumentoFM());

    

     s2.visualiza();

     try{ System.in.read();
          System.exit(0);
        }
     catch(Exception e){};

   }



   public static void main(String args[])
   { new E13e();
   }


   
   public class InstrumentoFM extends Dispositivo
   {
      Curva        curva1FM, curva2FM, curva3FM;
      Envoltoria   env1FM   = new Envoltoria();
      Envoltoria   env2FM   = new Envoltoria();
      Envoltoria   env3FM   = new Envoltoria();

      Oscilador o1, o2;
      Somador   somador;


     public InstrumentoFM()
     { super();

       frequencia       = 440;
       duracao          = 1;
       ganho            = 10;

       prepara();
     }


     private void prepara()
     {
       curva1FM = new Curva(720);
       curva1FM.addPonto(  0f, 10*frequencia);
       curva1FM.addPonto(720f, frequencia);
       //curva1.addPonto(  0f, 200f);
       //curva1.addPonto(720f, 200f);

       curva2FM = new Curva(720);
       curva2FM.addPonto(0f, 0f);
       curva2FM.addPonto(30f, 1000f);
       curva2FM.addPonto(600f, 300f);
       curva2FM.addPonto(720f, 0f);

       curva3FM = new Curva(720);
       curva3FM.addPonto(  0f, 10*frequencia);
       curva3FM.addPonto(720f, 10*frequencia);

       env1FM.setCURVA(curva1FM);
       env2FM.setCURVA(curva2FM);
       env3FM.setCURVA(curva3FM);

       env2FM.setGanho(3);

       o2 = new Oscilador(env1FM);
       o2.setFrequencia(180);
       somador = new Somador(env3FM, o2);

       o1 = new Oscilador(env2FM, somador);

     }

    /**
	 * Retorna o valor corrente na saída do intrumento.
	 *
	 * @return a saída corresnte do intrument.
	 */
	 public float getSaida()
    { return o1.getSaida();
    }


    /**
     * Aciona o clock de modo a atualizar a saída deste instrumento.
     */
    public void clock()
    { o2.clock();
      o1.clock();
    }

    public void setFrequencia(float f)
    { frequencia = f;
      prepara();
    }
    
    /**
     * Atribui um valor ao ganho.
     *
     * @param ganho_  o ganho do instrumento.
     */
    public void setGanho(float ganho_)
    { ganho = ganho_;
    }
    

  }

}