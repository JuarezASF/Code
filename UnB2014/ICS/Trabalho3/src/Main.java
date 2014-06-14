import java.awt.Color;
import javax.swing.JFrame;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.LogarithmicAxis;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.plot.PiePlot3D;
import org.jfree.chart.plot.XYPlot;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;
import org.jfree.util.Rotation;
import org.jfree.data.xy.*;


import sintese.Oscilador;
import sintese.Envoltoria;
import sintese.Som;
import sintese.InstrumentoAditivo;
import sintese.Curva;

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
	
	public static void main(String[] args) {
			demo3();
		}

}
