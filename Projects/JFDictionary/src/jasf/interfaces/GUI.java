package jasf.interfaces;

import jasf.dictionary.Fachada;
import jasf.dictionary.itemDicionario.ItemDicionario;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JTextField;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.DefaultListModel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JList;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.ListModel;
import javax.swing.ListSelectionModel;

public class GUI extends JFrame {

	private Fachada fachada;
	private JPanel contentPane;
	private JTextField txf_palavraAlvo;
	
	private ListModel listMdl_palavras;

	/**
	 * Create the frame.
	 */
	public GUI() {
		setTitle("JASF Dictionary");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JButton btn_buscar = new JButton("Buscar");
		btn_buscar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
			}
		});
		btn_buscar.setBounds(148, 32, 89, 23);
		contentPane.add(btn_buscar);
		
		txf_palavraAlvo = new JTextField();
		txf_palavraAlvo.setBounds(23, 33, 125, 20);
		contentPane.add(txf_palavraAlvo);
		txf_palavraAlvo.setColumns(10);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(23, 64, 125, 175);
		contentPane.add(scrollPane);
		
		listMdl_palavras = new DefaultListModel();
		JList list_palavras = new JList(listMdl_palavras);
		scrollPane.setViewportView(list_palavras);
		list_palavras.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);
		list_palavras.setLayoutOrientation(JList.VERTICAL);
		list_palavras.setVisibleRowCount(-1);
		
		JTextArea txtrOlMundo = new JTextArea();
		txtrOlMundo.setText("Ol\u00E1 Mundo!");
		txtrOlMundo.setToolTipText("As defini\u00E7\u00F5es da palavra selecionada aparecer\u00E3o aqui.");
		txtrOlMundo.setEditable(false);
		txtrOlMundo.setBounds(148, 64, 265, 175);
		contentPane.add(txtrOlMundo);
		
		JMenuBar menuBar = new JMenuBar();
		menuBar.setBounds(0, 0, 434, 21);
		contentPane.add(menuBar);
		
		JMenu mnFile = new JMenu("File");
		menuBar.add(mnFile);
		
		JMenuItem mntmCarregarDicionrio = new JMenuItem("Carregar Dicion\u00E1rio");
		mnFile.add(mntmCarregarDicionrio);
		
		JMenuItem mntmSalvarDicionrio = new JMenuItem("Salvar Dicion\u00E1rio");
		mnFile.add(mntmSalvarDicionrio);
		
		JMenuItem mntmConfigurar = new JMenuItem("Configurar");
		mnFile.add(mntmConfigurar);
		
		JMenu mnDicionrio = new JMenu("Dicion\u00E1rio");
		menuBar.add(mnDicionrio);
		
		JMenuItem mntmAdicionarPalavra = new JMenuItem("Adicionar Palavra");
		mnDicionrio.add(mntmAdicionarPalavra);
		
		JMenuItem mntmEditarPalavra = new JMenuItem("Editar Palavra");
		mnDicionrio.add(mntmEditarPalavra);
		
		JMenuItem mntmRemoverPalavra = new JMenuItem("Remover Palavra");
		mnDicionrio.add(mntmRemoverPalavra);
		
		JMenuItem mntmImprimirDicionrio = new JMenuItem("Imprimir Dicion\u00E1rio");
		mnDicionrio.add(mntmImprimirDicionrio);
	
	
		this.inicializar();
	}
	
	private void inicializar(){
		this.inicializarFachada();
		this.inicializarLista();
	}
	
	private void inicializarFachada(){
		try{
		fachada = new Fachada("./meusDados.ser");
		}
		catch(Exception E){
			final JPanel panel = new JPanel();
			JOptionPane.showMessageDialog(panel, E.getMessage(), "Erro Fatal", JOptionPane.ERROR_MESSAGE);
			E.printStackTrace();
			System.exit(0);
		}
		}
	
	private void inicializarLista(){
		ItemDicionario[] palavras = fachada.getArrayPalavras();
	
		for(int i = 0; i < palavras.length; i++){
			String nome_atual = palavras[i].getNome();
			((DefaultListModel) listMdl_palavras).addElement(nome_atual);
		}
	}
}
