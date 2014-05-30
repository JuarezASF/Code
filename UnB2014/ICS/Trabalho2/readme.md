#Introdução à Computação Sônica
##Trabalho 2 - Síntese Aditiva

* Utilizaremos a biblioteca Síntese, dispoibilizada pelo profess or Arsela, para implementar um projeto básico de síntese aditiva.
* As espeficiações do trabalho podem ser vistas na [página do professor](http://www.cic.unb.br/docentes/lcmm/deptcic2014_1/ics/trabalhos.html#e2)
* A documentação e o downlaod da biblioteca também são acessoados pelo mesmo link a cima.
* [Link direto para a documentação](http://www.cic.unb.br/docentes/lcmm/sintese/javadoc/)

##Como Compilar e Rodar do Terminal
###Compilar:
* esteja na pasta do projeto(não em src nem em bin)
        
        javac -d bin/ -cp sintese.jar:.:./src/ src/*.java src/SomJASF/*.java src/SomJASF/Instrumentos/*.java src/GUI/*.java


* parâmetros:        
  * -d bin/ coloca o resultado da compilação nessa pasta
  * -cp sintese.jar:. define os diretórios onde procurar código; acrescentamos aqui a biblioteca do professor arsela e o diretório atual "."
  
##Rodar
* mude para bin/
* execute:

        java src.Trabalho2 
* é importante que você esteja em bin/, pois é aí onde se encontra o .jar utilizado

## Gerar o Javadoc
* esteja na pasta do projeto e execute:
        
        javadoc -d doc/ -sourcepath src/ -subpackages SomJASF:GUI -charset "UTF-8"  src/*.java


        
* parâmetros:
  * -charset : define a codificação. Importante para gerar corretamente! Caso contrário teremos caracteres não reconhecidos na documentação e a coisa fica feia!! 
