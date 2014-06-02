package SomJASF;

import java.awt.Color;
import java.awt.Font;
import java.util.ArrayList;

import javax.swing.JFrame;

import sintese.*;

import org.math.plot.*;
import org.math.plot.plotObjects.BaseLabel;
import org.math.plot.utils.Array;

public class RAN extends Oscilador{
	
	private float f_ran;
	private Multiplicador envFinal;

	
	private Envoltoria randomEnv;
	private Envoltoria ganhoEnv;
	

	/**
	 * Gera RAN com amplitude definida por devAmplitude e freq de pontos
	 * de quebra definida por new-f-ran
	 * @param devAmplitude
	 * @param new_f_ran
	 */
	public RAN(Envoltoria devAmplitude, float new_f_ran) {
		ganhoEnv = devAmplitude;
		generateRandomEnv(new_f_ran);

		setRAN();
	}

	/**
	 * Construtor padrão. Sera amplitude para 100 e frequencia
	 * de pontos de quebra em 60
	 */
	public RAN() {
		super();
		initializeConstant(100, 60);
	}
	
	/**
	 * Gera RAN com amplitude definida por devAmplitude e freq de pontos
	 * de quebra definida por new-f-ran
	 * @param devAmplitude
	 * @param new_f_ran
	 */
	public RAN(float amplitude, float new_f_ran) {
		super();
		initializeConstant(amplitude, new_f_ran);
	
	}
	
	private void initializeConstant(float amplitude, float new_f_ran){
		//cria envotória padrão para amplitude
		Envoltoria devAmplitude = new Envoltoria();
		Curva curva = new Curva(720);
		curva.addPonto(0f, amplitude);
		curva.addPonto(720f, amplitude);
		devAmplitude.setCURVA(curva);
		ganhoEnv = devAmplitude;
		
		//cria envoltória aleatória com base em fran
		f_ran = new_f_ran;
		generateRandomEnv(new_f_ran);
		
		setRAN();
	}
	
	/**
	 * Configura o dispositivo RAN, isto é, seta o multiplicador
	 * para a nova envoltória randômica e nova envoltória de ganho
	 * 
	 * Finalmente, seta o dispositivo de ganho do oscilador
	 * para a saída do novo multiplicador
	 */
	private void setRAN(){
		setFrequencia(0);
		setFase(90);
		envFinal = new Multiplicador(randomEnv, ganhoEnv);
		setDispositivoAmplitude(envFinal);
	}


	/**
	 * Gera Envoltória aleatória com f_ran potnos espaçados de 720/f_ran 
	 * @param new_f_ran número de pontos de quebra na envoltoria aleatória
	 */
	private void generateRandomEnv(float new_f_ran){
		Curva curv = new Curva(720);
		float amplitude = 1f;
		float passo = 720f/new_f_ran;
		for(float x = 0; x <= 720; x+= passo){
			float myRand = getRandomNumber(amplitude);
			curv.addPonto(x, myRand);
		}
		
		this.randomEnv = new Envoltoria();
		this.randomEnv.setCURVA(curv);
	}
	/**
	 * Gera um número pseudoaleatório entre -A e +A
	 * @param amplitude
	 * @return
	 */
	private float getRandomNumber(float amplitude){
		float random = 2f*amplitude*((float)Math.random()) - amplitude;
		
		return random;
	}
		
	
	/**
	 * Gera um gráfico da envoltória aleatória de -1 a +1 criada
	 * considera que o tamanho máximo da tabela é 720
	 * Se for usar mais do que isso irá dar pau! orriga se necessário!!
	 */
	public void visualiza(){
		// create your PlotPanel (you can use it as a JPanel)
		  Plot2DPanel plot = new Plot2DPanel();
		 
		  

		  Tabela tab = randomEnv.getCURVA();
		  
		  int tamanho_curva = tab.getTamanhoTabela();
		  
		  ArrayList<Double> x = new ArrayList<Double>(); 
		  ArrayList<Double> y = new ArrayList<Double>(); 
		  float a = getGanho();
		  for(int i = 0; i <= f_ran; i++){
			  x.add((double )i*tamanho_curva/f_ran);
			  y.add((double )tab.getValorNoIndice(i)*a) ;
		  }
		  
		  // add a line plot to the PlotPanel
		  double[] x_array =new double[x.size()];
		  double[] y_array =new double[y.size()];
		  for (int i = 0; i < x_array.length; i++) {
			  x_array[i] = x.get(i).doubleValue();  // java 1.4 style
			  y_array[i] = y.get(i).doubleValue();  // java 1.4 style
		  }
		  
		  plot.addLinePlot("Rand Data", x_array, y_array);
		  // add a title
          BaseLabel title = new BaseLabel("Dispositivo RAN", Color.RED, 0.5, 1.1);
          title.setFont(new Font("Courier", Font.BOLD, 20));
          plot.addPlotable(title);
          
       // legend at SOUTH
          plot.addLegend("Pontos da Tabela");
          
          
          double PI = 3.1415926535;
       // customize X axe
          // rotate light labels
          plot.getAxis(0).setLightLabelAngle(-PI / 4);
          // change axe title position relatively to the base of the plot
          plot.getAxis(0).setLabelPosition(0.5, -0.15);

          // customize Y axe
          // rotate light labels
          plot.getAxis(1).setLightLabelAngle(-PI / 4);
          // change axe title position relatively to the base of the plot
          plot.getAxis(1).setLabelPosition(-0.15, 0.5);
          // change axe title angle
          plot.getAxis(1).setLabelAngle(-PI / 2);
		  
		  // put the PlotPanel in a JFrame, as a JPanel
		  JFrame frame = new JFrame("Rand Envoltoria");
		  frame.setContentPane(plot);
		  frame.setVisible(true);
		  frame.setSize(320, 240);
		  frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	/**
	 * Cria uma nova tabela aleatória e seta a saída do dispositivo
	 * para esse novo padrão gerado
	 */
	public void geraNovoPadraoAleatorio(){
		generateRandomEnv(getF_ran());
		setRAN();
		
	}

	/**
	 * retorna a frequência de pontos de quebra
	 * @return
	 */
	public float getF_ran() {
		return f_ran;
	}

	/**
	 * seta novo f_ran e gera novo padrão aleatório com essa definição
	 * @param f_ran
	 */
	public void setF_ran(float f_ran) {
		this.f_ran = f_ran;
		geraNovoPadraoAleatorio();
	}
	
	/**
	 * seta o ganho do oscilador e aplica mesmo ganho as
	 * envoltórias...finalmente, seta o RAN para a nova envoltória gerada
	 */
	public void setGanho(float k){
		super.setGanho(k);
		this.ganhoEnv.setGanho(k);
		setRAN();
	}
	
	public void setGanhoDispositivo(Envoltoria env){
		ganhoEnv = env;
		setRAN();
	}
	
	
	/**
	 * Seta a nova duração, também altera as envoltórias,
	 * não sei se isso é necessário...mas taí
	 * 
	 */
	public void setDuracao(float D){
		super.setDuracao(D);
		ganhoEnv.setDuracao(D);
		randomEnv.setDuracao(D);
		
		setRAN();
	}
	
}
