<div align = "center">

[
    <img src="https://raw.githubusercontent.com/carlos-antunis-physics/carlos-antunis-physics/refs/heads/main/assets/UFAL.png" width="150"></img>
](#---)

# Frontend do projeto de matematica discreta

**Autores:** [Carlos](https://github.com/carlos-antunis-physics/), [Filipe](https://github.com/FilipeFortaleza), Flavia, [Giovanna](https://github.com/giovannaspace), [Mirian](https://github.com/miriangomes)

[![HTML](https://img.shields.io/badge/HTML-efefef.svg?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAxMjggMTI4Ij48cGF0aCBmaWxsPSIjRTQ0RDI2IiBkPSJNMTkuMDM3IDExMy44NzZMOS4wMzIgMS42NjFoMTA5LjkzNmwtMTAuMDE2IDExMi4xOTgtNDUuMDE5IDEyLjQ4eiIvPjxwYXRoIGZpbGw9IiNGMTY1MjkiIGQ9Ik02NCAxMTYuOGwzNi4zNzgtMTAuMDg2IDguNTU5LTk1Ljg3OEg2NHoiLz48cGF0aCBmaWxsPSIjRUJFQkVCIiBkPSJNNjQgNTIuNDU1SDQ1Ljc4OEw0NC41MyAzOC4zNjFINjRWMjQuNTk5SDI5LjQ4OWwuMzMgMy42OTIgMy4zODIgMzcuOTI3SDY0em0wIDM1Ljc0M2wtLjA2MS4wMTctMTUuMzI3LTQuMTQtLjk3OS0xMC45NzVIMzMuODE2bDEuOTI4IDIxLjYwOSAyOC4xOTMgNy44MjYuMDYzLS4wMTd6Ii8+PHBhdGggZmlsbD0iI2ZmZiIgZD0iTTYzLjk1MiA1Mi40NTV2MTMuNzYzaDE2Ljk0N2wtMS41OTcgMTcuODQ5LTE1LjM1IDQuMTQzdjE0LjMxOWwyOC4yMTUtNy44Mi4yMDctMi4zMjUgMy4yMzQtMzYuMjMzLjMzNS0zLjY5NmgtMy43MDh6bTAtMjcuODU2djEzLjc2MmgzMy4yNDRsLjI3Ni0zLjA5Mi42MjgtNi45NzguMzI5LTMuNjkyeiIvPjwvc3ZnPg==&style=flat-square)](#---)
[![CSS](https://img.shields.io/badge/CSS-efefef.svg?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAxMjggMTI4Ij48cGF0aCBmaWxsPSIjMTU3MkI2IiBkPSJNMTguODE0IDExNC4xMjNMOC43NiAxLjM1MmgxMTAuNDhsLTEwLjA2NCAxMTIuNzU0LTQ1LjI0MyAxMi41NDMtNDUuMTE5LTEyLjUyNnoiLz48cGF0aCBmaWxsPSIjMzNBOURDIiBkPSJNNjQuMDAxIDExNy4wNjJsMzYuNTU5LTEwLjEzNiA4LjYwMS05Ni4zNTRoLTQ1LjE2djEwNi40OXoiLz48cGF0aCBmaWxsPSIjZmZmIiBkPSJNNjQuMDAxIDUxLjQyOWgxOC4zMDJsMS4yNjQtMTQuMTYzSDY0LjAwMVYyMy40MzVoMzQuNjgybC0uMzMyIDMuNzExLTMuNCAzOC4xMTRoLTMwLjk1VjUxLjQyOXoiLz48cGF0aCBmaWxsPSIjRUJFQkVCIiBkPSJNNjQuMDgzIDg3LjM0OWwtLjA2MS4wMTgtMTUuNDAzLTQuMTU5LS45ODUtMTEuMDMxSDMzLjc1MmwxLjkzNyAyMS43MTcgMjguMzMxIDcuODYzLjA2My0uMDE4di0xNC4zOXoiLz48cGF0aCBmaWxsPSIjZmZmIiBkPSJNODEuMTI3IDY0LjY3NWwtMS42NjYgMTguNTIyLTE1LjQyNiA0LjE2NHYxNC4zOWwyOC4zNTQtNy44NTguMjA4LTIuMzM3IDIuNDA2LTI2Ljg4MUg4MS4xMjd6Ii8+PHBhdGggZmlsbD0iI0VCRUJFQiIgZD0iTTY0LjA0OCAyMy40MzV2MTMuODMxSDMwLjY0bC0uMjc3LTMuMTA4LS42My03LjAxMi0uMzMxLTMuNzExaDM0LjY0NnptLS4wNDcgMjcuOTk2djEzLjgzMUg0OC43OTJsLS4yNzctMy4xMDgtLjYzMS03LjAxMi0uMzMtMy43MTFoMTYuNDQ3eiIvPjwvc3ZnPg==&style=flat-square)](#---)
[![Javascript](https://img.shields.io/badge/Javascript-efefef.svg?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAxMjggMTI4Ij48cGF0aCBmaWxsPSIjRjBEQjRGIiBkPSJNMS40MDggMS40MDhoMTI1LjE4NHYxMjUuMTg1SDEuNDA4eiIvPjxwYXRoIGZpbGw9IiMzMjMzMzAiIGQ9Ik0xMTYuMzQ3IDk2LjczNmMtLjkxNy01LjcxMS00LjY0MS0xMC41MDgtMTUuNjcyLTE0Ljk4MS0zLjgzMi0xLjc2MS04LjEwNC0zLjAyMi05LjM3Ny01LjkyNi0uNDUyLTEuNjktLjUxMi0yLjY0Mi0uMjI2LTMuNjY1LjgyMS0zLjMyIDQuNzg0LTQuMzU1IDcuOTI1LTMuNDAzIDIuMDIzLjY3OCAzLjkzOCAyLjIzNyA1LjA5MyA0LjcyNCA1LjQwMi0zLjQ5OCA1LjM5MS0zLjQ3NSA5LjE2My01Ljg3OS0xLjM4MS0yLjE0MS0yLjExOC0zLjEyOS0zLjAyMi00LjA0NS0zLjI0OS0zLjYyOS03LjY3Ni01LjQ5OC0xNC43NTYtNS4zNTVsLTMuNjg4LjQ3N2MtMy41MzQuODkzLTYuOTAyIDIuNzQ4LTguODc3IDUuMjM1LTUuOTI2IDYuNzI0LTQuMjM2IDE4LjQ5MiAyLjk3NSAyMy4zMzUgNy4xMDQgNS4zMzIgMTcuNTQgNi41NDUgMTguODczIDExLjUzMSAxLjI5NyA2LjEwNC00LjQ4NiA4LjA4LTEwLjIzNCA3LjM3OC00LjIzNi0uODgxLTYuNTkyLTMuMDM0LTkuMTM5LTYuOTQ5LTQuNjg4IDIuNzEzLTQuNjg4IDIuNzEzLTkuNTA4IDUuNDg1IDEuMTQzIDIuNDk5IDIuMzQ0IDMuNjMgNC4yNiA1Ljc5NSA5LjA2OCA5LjE5OCAzMS43NiA4Ljc0NiAzNS44My01LjE3Ni4xNjUtLjQ3OCAxLjI2MS0zLjY2Ni4zOC04LjU4MXpNNjkuNDYyIDU4Ljk0M0g1Ny43NTNsLS4wNDggMzAuMjcyYzAgNi40MzguMzMzIDEyLjM0LS43MTQgMTQuMTQ5LTEuNzEzIDMuNTU4LTYuMTUyIDMuMTE3LTguMTc1IDIuNDI3LTIuMDU5LTEuMDEyLTMuMTA2LTIuNDUxLTQuMzE5LTQuNDg1LS4zMzMtLjU4NC0uNTgzLTEuMDM2LS42NjctMS4wNzFsLTkuNTIgNS44M2MxLjU4MyAzLjI0OSAzLjkxNSA2LjA2OSA2LjkwMiA3LjkwMSA0LjQ2MiAyLjY3OCAxMC40NTkgMy40OTkgMTYuNzMxIDIuMDU5IDQuMDgyLTEuMTg5IDcuNjA0LTMuNjUyIDkuNDQ4LTcuNDAxIDIuNjY2LTQuOTE1IDIuMDk0LTEwLjg2NCAyLjA3LTE3LjQ0NC4wNi0xMC43MzUuMDAxLTIxLjQ2OC4wMDEtMzIuMjM3eiIvPjwvc3ZnPg==&style=flat-square)](#---)
[![Web Assembly](https://img.shields.io/badge/Web%20Assembly-efefef.svg?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAxMjggMTI4Ij48cGF0aCBmaWxsPSIjNjU0ZmYwIiBkPSJNLjIyMy4yMjJ2MTI3LjU1NWgxMjcuNTU1Vi4yMjJINzguNTk0Yy4wMTQuMjI3LjAzNi40NTUuMDM2LjY4NiAwIDguMDgtNi41NSAxNC42MjYtMTQuNjMgMTQuNjI2LTguMDc4IDAtMTQuNjI1LTYuNTQ2LTE0LjYyNS0xNC42MjYgMC0uMjMxLjAyMi0uNDU5LjAzMS0uNjg2em0yOS41OTUgNjguNzQ2aDguNDQ1bDUuNzgyIDMwLjczOGguMTA3bDYuOTY4LTMwLjczOGg3LjkwOGw2LjI2NSAzMS4xMTloLjEwNmw2LjU5Ny0zMS4xMTloOC4yODRsLTEwLjc2NSA0NS4xNTZINjEuMTJsLTYuMjEzLTMwLjczOEg1NC44bC02LjcgMzAuNzM4aC04LjU1N3ptNTkuOTk0IDBoMTMuMzM0bDEzLjI4NCA0NS4xNTZoLTguNzdsLTIuODc5LTEwLjA1MUg4OS41OWwtMi4yMTIgMTAuMDVoLTguNVpNOTQuODk1IDgwLjFsLTMuNjg0IDE2LjU3aDExLjQ3M0w5OC40NDggODAuMVoiLz48L3N2Zz4K&style=flat-square)](#---)
[![Netlify technology](https://img.shields.io/badge/Netlify-efefef.svg?logo=data:image/svg%2bxml;base64,PHN2ZyB2aWV3Qm94PSIwIDAgMTI4IDEyOCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48cGF0aCBkPSJNODAuNDYgODIuNjA1aC04Ljc3N2wtLjczNC0uNzMzVjYxLjMyNmMwLTMuNjU2LTEuNDM2LTYuNDg5LTUuODQ0LTYuNTg4LTIuMjY5LS4wNi00Ljg2NCAwLTcuNjM4LjExbC0uNDE2LjQyNXYyNi41ODlsLS43MzMuNzMzSDQ3LjU0bC0uNzMzLS43MzNWNDYuNzY0bC43MzMtLjczM2gxOS43NTNjNy42NzcgMCAxMy44OTkgNi4yMiAxMy44OTkgMTMuODk4djIxLjk0M2wtLjczMy43MzNaIiBmaWxsPSIjMDE0ODQ3Ii8+PHBhdGggZD0iTTU4Ljk0MiAxMTkuOTAydi0yNi4zM2wuNzMzLS43MzRoOC43OTdsLjczMy43MzN2MjYuMzMxbC0uNzMzLjczM2gtOC43OTZ6bTAtODQuODM4VjguNzM0TDU5LjY3NSA4aDguNzk3bC43MzMuNzMzdjI2LjMzMWwtLjczMy43MzNoLTguNzk2em02OC4zMzUgMzQuMzg1SDkyLjE2OWwtLjczMy0uNzMzVjU5LjkybC43MzMtLjczM2gzNS4xMDhsLjczMy43MzN2OC43OTd6bS05MS40MzYgMEguNzMzTDAgNjguNzE2VjU5LjkybC43MzMtLjczM2gzNS4xMDhsLjczMy43MzN2OC43OTd6bS04LjQ5LTM1LjYzM3YtMS4yMDlsNi4wMzQtNi4wMzNoMS4yMDhsOS4yMjMgOS4yMjN2Ni4zOWwtLjg1Mi44NTJoLTYuMzl6bTcuMjQyIDY4LjIzNWgtMS4yMDhsLTYuMDMzLTYuMDMzdi0xLjIwOWw5LjIyMy05LjIyMmg2LjM5bC44NTEuODUxdjYuMzl6IiBmaWxsPSIjMDViZGJhIi8+PC9zdmc+&style=flat-square)](#---)

</div>

Projeto de **Criptografia RSA** como **atividade avaliativa** da disciplina de **Matemática Discreta** do **1⁰ período** do curso de **Engenharia da Computação** ministrado no semestre **2024.2** no **IC - UFAL** pelo professor Bruno Almeida Pimentel.

>   [!NOTE]
>
>   Neste repositório estão também dispostas nossas soluções da [lista de atividades](lista-de-questoes/README.md) de preparação para o projeto de Criptografia RSA na linguagem `C`.

##  Licença

Os arquivos aqui dispostos, para a construção da página web, foram desenvolvidas sob a [licença MIT](./LICENSE).

### Bibliotecas e dependências

- [**Emscripten.**](https://emscripten.org/) Um compilador completo da linguagem `C` para WebAssembly.    

- [**GNU Multiple Precision Arithmetic Library (GMP).**](https://gmplib.org/) Uma biblioteca livre para aritmética de precisão arbitrária, distribuída segundo a Licença [**GNU LGPL v3**](https://www.gnu.org/licenses/lgpl-3.0.html). Para a substituição da biblioteca no backend (a dispusemos [num repositório a parte](https://github.com/carlos-antunis-physics/backend-rsa)) de maneira estática, basta efetuar sua instalação via emscripten.

####    Instalação do GMP via emscripten

Para instalar o GMP via emscripten, é necessário primeiramente possuir tal software em seu dispositivo. Para isso, utilize:

```bash
sudo apt-get install git
git clone "https://github.com/emscripten-core/emsdk.git"
cd emsdk
git pull
./emsdk install latest
source ./emsdk_env.sh
./emsdk activate
```

A seguir instale o GMP via emscripten no **diretório raiz** deste projeto.

```bash
wget https://gmplib.org/download/gmp/gmp-[desired-version].tar.xz
tar -xf gmp-*.tar.xz
rm gmp-*.tar.xz
cd gmp-*
emconfigure ./configure --disable-assembly --host=none --build=none
emmake make
```

após esse processo haverá um diretório `gmp-*/` na pasta atual contendo a biblioteca disponível para emscripten. Por fim, para compilar o código `C` para `Web Assembly` utilize

```bash
emcc src/backendRSA.c -o rsa.js -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS=[ccall]
```
