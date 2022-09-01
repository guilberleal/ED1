/*
    Disciplina: Estrutura de Dados I
    Professor: Ivairton M. Santos
    Alunos: Kalmon Valdão e Athur Rosa
    compilar: node morse.js
*/

// ---- GLOBAL
var arvore = criarEstrutura();
const fs = require('fs');


//-- MAIN()
CreatArvore();
//console.info(JSON.stringify(arvore));
tradutor();
preOrder(arvore,"");

function preOrder(arvoretemp,rota){
    if(arvoretemp.letra!="*"){
        console.log("Rota: "+rota+" Letra:"+arvoretemp.letra+"\n");
    }
    if(arvoretemp.dir!=null){
        preOrder(arvoretemp.dir,rota+".");
    }
    if(arvoretemp.esq!=null){
        preOrder(arvoretemp.esq,rota+"-");
    }
}

//Função dedicada a criar arvore.
function CreatArvore(){
    let arvorePont = arvore;
    let text = fs.readFileSync('dicionario.txt','utf8');
    for(var i=0;i<text.length;i++){
        //Esquerda
        if(text[i]=="."){
            if(arvorePont.dir==null){
                arvorePont.dir = criarEstrutura(); 
            }
            arvorePont = arvorePont.dir;
        //Direita
        }else if(text[i]=="-"){
            if(arvorePont.esq==null){
                arvorePont.esq = criarEstrutura(); 
            }
            arvorePont = arvorePont.esq;
        //Obter letra para ser adicionado a arvore.
        }else if(text[i]!="\n" && text[i]!=" "){
            arvorePont.letra=text[i];
            arvorePont = arvore;

        }
    }
}

function tradutor(){
    var textoFinal="";
    let arvorePont = arvore;
    let text = fs.readFileSync('texto.txt','utf8');
    console.log("CODIGO:\n"+text);
    for(var i=0;i<text.length;i++){
        //Esquerda
        if(text[i]=="."){
            arvorePont = arvorePont.dir;
        //Direita
        }else if(text[i]=="-"){
            arvorePont = arvorePont.esq;
        //Obter letra para ser adicionado a arvore.
        }else if(text[i]==" "){
            if(arvorePont.letra!="*"){
                textoFinal+=arvorePont.letra;
            }
            arvorePont = arvore;
        }else if(text[i]=="/"){
            textoFinal+=" ";
            arvorePont = arvore;
        }else if(text[i]=="\n"){
            textoFinal+=arvorePont.letra+"\n";
            arvorePont = arvore;
        }
    }
    console.log("TRADUÇÃO:\n"+textoFinal);
}

//Cria a estrutura da arvore e retorna;
function criarEstrutura(){
    var TempArvore = {
        esq: null,
        dir: null,
        letra: "*"
    }
    return TempArvore;
}