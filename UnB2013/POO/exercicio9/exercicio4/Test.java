// Insira as linhas abaixo como primeiras linhas em seu programa de teste.
// Tais linhas garantem que posssamos referenciar as classes Scanner e Locale.
// Explicaremos como isto funciona mais para frente, na aula sobre pacotes.
import java.util.Scanner;
import java.util.Locale;

public class Test {

 public static void main (String [] args) {

     /* A classe Scanner ajuda a ler dados da entrada, represtentada pelo objeto System.in. 
      A documentacao desta classe esta na URL abaixo:
      http://download.oracle.com/javase/1.5.0/docs/api/java/util/Scanner.html
      inserir a linha abaixo  
     */

     Scanner sc = new Scanner(System.in);



    /* use a linha abaixo para garantir que valores em ponto flutuante sao lidos esperando-se
     um ponto e nao uma virgula para a parte decimal: 
     por exemplo, sera esperado 2.3 e nao 2,3   
     */

     sc.useLocale(Locale.US);





     // lendo um inteiro: use para ler a opcao de operacao selecionada pelo usuario no exercicio

     System.out.println("Favor entre um inteiro e tecle Enter:");
     int i = sc.nextInt();
     System.out.println("Voce entrou o seguinte inteiro: " + i);


     // lendo uma linha: use para ler um nome do cliente

     System.out.println ("Favor entre uma linha e tecle Enter:");
     // pula o caracter de mudanca de linha '\n', ou seja o Enter, que foi digitado na leitura do inteiro acima
     String linha = sc.nextLine();
     // agora sim le a linha
     linha = sc.nextLine();
     System.out.println("Voce entrou a seguinte linha: " + linha);



     // lendo um double: se para ler valores a serem creditados, debitados, transferidos em contas

     System.out.println("Favor entre um valor de ponto flutuante e tecle Enter:");
     double d = sc.nextDouble();
     System.out.println("Voce entrou o seguinte valdo de ponto flutuante: " + d);



     // lendo uma string que nao tenha separadores (ex: espaco em branco, tab):
     // use para ler CPF e numero da conta, por exemplo  "123-X"

     System.out.println ("Favor entre uma string e tecle Enter:");
     String s = sc.next();
     System.out.println("Voce entrou a seguinte string: " + s);


 }

}