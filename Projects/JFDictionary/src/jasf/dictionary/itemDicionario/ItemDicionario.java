package jasf.dictionary.itemDicionario;

import java.util.Vector;

/**
 * @author Juarez Aires Sampaio Filho
 *
 */

public class ItemDicionario implements java.io.Serializable{
	private String nome;
	private Vector<String> definicao;
	
	/**
	 * Cria item de dicion�rio com o nome entrado e defini��o vazia
	 * @param nome
	 */
	public ItemDicionario(String nome){
		inicializa(nome, new Vector<String>());
	}
	
	/**
	 * Cria item de dicion�rio com nome e defini��o vazia
	 */
	public ItemDicionario(){
		inicializa(new String(""), new Vector<String>());
	}
	
	private void inicializa(String nome, Vector<String> def){
		setNome(nome);
		setDefinicao(def);
	}
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public Vector<String> getDefinicao() {
		return definicao;
	}
	public void setDefinicao(Vector<String> definicao) {
		this.definicao = definicao;
	}
	
	/**
	 * Adiciona defini��o ao vetor de defini��es
	 * @param def
	 */
	public void addDefinicao(String def){
		this.definicao.add(def);
	}
	
	/**
	 * Edita a (n-1)�sima defini��o.
	 * @param n
	 * @param def
	 * @throws Exception
	 */
	public void editaDefinicao(int n, String def)throws Exception{
		if(n >= getNDefinicoes())
			throw new Exception("Defini��o n�o encontrada!");
		
		this.definicao.set(n, def);
		
	}
	
	/**
	 * Limpa o vetor de defini��es
	 */
	public void limpaDefinicao(){
		this.definicao.clear();
	}
	
	/**
	 * Retorna n�mero de defini��es j� existentes
	 * @return
	 */
	public int getNDefinicoes(){
		return definicao.size();
	}
	
}
