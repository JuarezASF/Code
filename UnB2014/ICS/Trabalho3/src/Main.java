import javax.swing.JFrame;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PiePlot3D;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;
import org.jfree.util.Rotation;
import org.jfree.data.xy.*;

public class Main {
	
	public static double Gaussian(double x){
		double f = 1*Math.exp(-1.0*Math.pow((x - 0.0), 2)/(2*Math.pow(1, 2)));
		
		return f;
	}

	public static void main(String[] args) {
		XYSeries series = new XYSeries("Normal(0, 1)");
		for(double x = -3.0; x <= 3.0; x += 0.1){
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
		
		ChartPanel chartPanel = new ChartPanel(chart);
        painel.setContentPane(chartPanel);
        painel.setSize(new java.awt.Dimension(500, 270));
        painel.setVisible(true);
		
	}

}
