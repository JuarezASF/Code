package Interface;

import ClassesBásicas.*;
import Coleções.*;
import Interface.TerminalUserInterface;
import Listas.ListaAlunos;
import Listas.ListaCursos;
import Listas.ListaMatriculas;
import Repositórios.RepositorioAlunoArray;
import Repositórios.RepositorioCursoArray;
import Repositórios.RepositorioMatriculaArray;


public class Fachada {
	private static Fachada instanciaFachada;
	private CadastroAlunos alunos;
	private CadastroCursos cursos;
	private CadastroMatriculas matriculas;

	//-------------------------------------------------
	//-----------Construtores--------------------------
	//-------------------------------------------------
	private void initCadastro(){
		RepositorioAlunoArray newAlunos = new  RepositorioAlunoArray();
		RepositorioCursoArray newCursos = new RepositorioCursoArray();
		RepositorioMatriculaArray newMatriculas = new RepositorioMatriculaArray();
		
		this.alunos = new CadastroAlunos(newAlunos);
		this.cursos = new CadastroCursos(newCursos);
		this.matriculas = new CadastroMatriculas(newMatriculas);
	}
	
	private Fachada(){
		this.initCadastro();
	}
	
	public static Fachada obterInstancia(){
		if( instanciaFachada == null)
			{
			instanciaFachada = new Fachada();
			}
		return instanciaFachada;
		
	}
	
	
	//-------------------------------------------------
	//-----------Funções comuns------------------------
	//-------------------------------------------------
	public void cadastrarMatricula(Matricula newMtrc){
		
		if(newMtrc.getCurso() == null)
			{
			newMtrc.setCurso(this.cursos.maisVazio());
			}
		
		if(alunos.existe(newMtrc.getAluno())&&
				cursos.existe(newMtrc.getCurso()))
			{
			matriculas.cadastrar(newMtrc);
			TerminalUserInterface.displayMsg("Matrícula realizada com sucesso!");
			}
		
		else
			TerminalUserInterface.reportarErro("aluno ou curso não cadastrado!");
		}
	
	public void cadastarAluno(Aluno newAl){
		alunos.cadastrar(newAl);
	}
	
	public void cadastrarCurso(Curso newCrs){
		cursos.cadastrar(newCrs);
	}
	
	public void descadastrarCurso(Curso targetCr){
		ListaMatriculas listaMtrc = this.matriculas.ListaMatriculasCurso(targetCr);
		this.matriculas.descadastrar(listaMtrc);
		this.cursos.descadastrar(targetCr);
	}

	public void descadastrarAluno(Aluno targetAl){
		ListaMatriculas listaMtrc = this.matriculas.ListaMatriculasAluno(targetAl);
		this.matriculas.descadastrar(listaMtrc);
		this.alunos.descadastrar(targetAl);
	}
	
	public void descadastrarMatricula(Matricula targetMtrc){
		this.matriculas.descadastrar(targetMtrc);
	}
	
	public Aluno procurarAluno(String targetName){
		return this.alunos.procurar(targetName);
	}
	
	public Curso procurarCurso(String targetCode){
		return this.cursos.procurar(targetCode);
	}
	
	public Matricula procurarMatricula(int targetNumber){
		return this.matriculas.procurar(targetNumber);
	}

	public Matricula procurarMatricula(Matricula targetMtrc){
		return this.matriculas.procurar(targetMtrc);
	}

	
	public void atualizarAluno(Aluno target){
		this.alunos.atualizar(target);
	}

	public void atualizarCurso(Curso target){
		this.cursos.atualizar(target);
	}
	
	public ListaMatriculas getListAllMtrc(){
		return this.matriculas.ListaMatriculas();
	}

	public ListaMatriculas getListAllMtrcByCr(Curso targetCr){
		if(cursos.existe(targetCr))
			return this.matriculas.ListaMatriculasCurso(targetCr);
		else
			{
			ListaMatriculas  empty = new ListaMatriculas();
			return empty;
			}
	}

	public ListaMatriculas getListAllMtrcByAl(Aluno targetAl){
		if(alunos.existe(targetAl))
			return this.matriculas.ListaMatriculasAluno(targetAl);
		else
			{
			ListaMatriculas  empty = new ListaMatriculas();
			return empty;
			}
	}

	public ListaCursos getListAllCr(){
		return this.cursos.ListaCursos();
	}

	public ListaAlunos getListAllAl(){
		return this.alunos.ListaAlunos();
	}
	
	public boolean existe(Curso target){
		return this.cursos.existe(target);
	}

	public boolean existe(Aluno target){
		return this.alunos.existe(target);
	}
	
	
}//fim da classe fachada
