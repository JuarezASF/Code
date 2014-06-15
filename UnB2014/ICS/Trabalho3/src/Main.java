import java.awt.Color;

import javax.swing.JFrame;
import javax.vecmath.Vector2d;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.LogarithmicAxis;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.plot.XYPlot;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;
import org.jfree.data.xy.*;

import sintese.Multiplicador;
import sintese.Oscilador;
import sintese.Envoltoria;
import sintese.Som;
import sintese.Curva;
import sintese.Somador;

public class Main {

	public static void demo1(){
		XYSeries series = new XYSeries("Normal(0, 1)");
		for(double x = 220; x <= 880; x += 10){
			series.add(x, Gaussian(x));
		}
		XYDataset xyDataset = new XYSeriesCollection(series);

		JFreeChart chart = ChartFactory.createXYAreaChart
				("Sample XY Chart", // Title
				"x", // X-Axis label
				"f(x)", // Y-Axis label
				xyDataset // Dataset
				);
		
		
		
		JFrame painel = new JFrame();
		
		final XYPlot plot = chart.getXYPlot();
        final NumberAxis domainAxis = new LogarithmicAxis("Log(y)");
        plot.setDomainAxis(domainAxis);
        chart.setBackgroundPaint(Color.white);
		ChartPanel chartPanel = new ChartPanel(chart);
        painel.setContentPane(chartPanel);
        painel.setSize(new java.awt.Dimension(500, 270));
        painel.setVisible(true);
		
	
	}

	
	public static double Gaussian(double x){
		double f = 1*Math.exp(-1.0*Math.pow((x - 440.0), 2)/(2*Math.pow(110.0, 2)));
		
		return f;
	}

	public static void demo2(){
		
		EnvoltoriaGaussiana gauss = new EnvoltoriaGaussiana(100, 15, 10000);
		gauss.setDuracaoCiclo(2.5f);
		gauss.setContador(360);
		
		EnvoltoriaLinearShepard freq = new EnvoltoriaLinearShepard(440);
		freq.setDuracaoCiclo(2.5f);
		freq.setContador(360);
		
		Oscilador osci = new Oscilador();
		osci.setDispositivoAmplitude(gauss);
		osci.setDispositivoFrequencia(freq);
		osci.setSR(44100);
		
		Som som = new Som(osci, 5);
		
		
		som.visualiza();
		
		
		
	}
	
	public static void demo3(){
		
		OsciladorShepard osci = new OsciladorShepard(440, 100, 15);
		osci.setDuracaoCiclo(2.5f);
		
		Som som = new Som(osci, 5);
		
		
		som.visualiza();
		
		
		
	}
	
	public static void demo4(){
		
		float media = 100;
		float var = 20;
		float duracao_ciclo = 5f;
		float duracao = 10f;
		
		OsciladorShepard osci1 = new OsciladorShepard(440, media, var);
		osci1.setDuracaoCiclo(duracao_ciclo);
		osci1.setPorcentagemCiclo(0f);
		
		OsciladorShepard osci2 = new OsciladorShepard(440, media, var);
		osci2.setDuracaoCiclo(duracao_ciclo);
		osci2.setPorcentagemCiclo(50f);
	
		OsciladorShepard osci3 = new OsciladorShepard(440, media, var);
		osci3.setDuracaoCiclo(duracao_ciclo);
		osci3.setPorcentagemCiclo(25f);
		
		OsciladorShepard osci4 = new OsciladorShepard(440, media, var);
		osci4.setDuracaoCiclo(duracao_ciclo);
		osci4.setPorcentagemCiclo(75f);
		
		Somador sum = new Somador(osci1, osci2);
		Somador sum2 = new Somador(osci3, osci4);
		
		
		Somador sumFinal = new Somador(sum, sum2);
		
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0.75);
		curva.addPonto(720f, 0.75);
	
		Envoltoria ganho = new Envoltoria(curva);
		ganho.setDuracao(duracao);
		
		Multiplicador som_final = new Multiplicador(ganho, sumFinal);
		
		Som som = new Som(som_final, duracao);
		
		som.visualiza();
	
	}
	
	public static void demo5(){
		
		float media = 100;
		float var = 20;
		float duracao_ciclo = 1f;

		
		OsciladorShepard osci1 = new OsciladorShepard(440, media, var);
		osci1.setDuracaoCiclo(duracao_ciclo);
		osci1.setPorcentagemCiclo(0f);

		XYSeries series = new XYSeries("FreqxAmp");
		XYSeries series2 = new XYSeries("AmpxTempo");
		XYSeries series3= new XYSeries("FreqxTempo");
		
		for(int i = 0; i <= duracao_ciclo*44100*0.5; i += 1){
			osci1.clock();
			osci1.clock();
			Vector2d data = osci1.getFreqAmpData();
			double x = data.x;
			double y = data.y;
			series.add(x, y);
			
			data = osci1.getTimeAmpData();
			x = data.x;
			y = data.y;
			series2.add(x, y);
			
			data = osci1.getTimeFreqData();
			x = data.x;
			y = data.y;
			series3.add(x, y);
		}
		XYDataset xyDataset = new XYSeriesCollection(series);
		XYDataset xyDataset2 = new XYSeriesCollection(series2);
		XYDataset xyDataset3 = new XYSeriesCollection(series3);
		
		JFreeChart chart = ChartFactory.createXYAreaChart
				("Sample XY Chart", // Title
				"frequência", // X-Axis label
				"amplitude", // Y-Axis label
				xyDataset // Dataset
				);
		
		JFrame painel = new JFrame();
		
		final XYPlot plot = chart.getXYPlot();
		plot.setDataset(2, xyDataset2);
		plot.setDataset(3, xyDataset3);
		        
		chart.setBackgroundPaint(Color.white);
		
		ChartPanel chartPanel = new ChartPanel(chart);
        
		painel.setContentPane(chartPanel);
        painel.setSize(new java.awt.Dimension(500, 270));
        painel.setVisible(true);
		
	
	}

	
	
	public static void main(String[] args) {
			demo5();
		}

}
