document.addEventListener('DOMContentLoaded', function () {
  // Banner de animação
  const banner1 = document.getElementById('banner1');
  const banner2 = document.getElementById('banner2');
  const banner3 = document.getElementById('banner3');

  banner1.classList.add('active');

  // Banner 1: duração de 6 segundos
  setTimeout(() => {
    banner1.classList.remove('active');
    banner2.classList.add('active', 'fade-in');
  }, 6000);

  // Banner 2: duração de 4 segundos
  setTimeout(() => {
    banner2.classList.remove('active');
    banner3.classList.add('active', 'fade-in');
  }, 9000);

  // Navegação entre Steps (independente do backend)
  window.nextStep = function () {
    document.getElementById('step1-content').classList.remove('active');
    document.getElementById('step2-content').classList.add('active');
  };

  window.prevStep = function () {
    document.getElementById('step2-content').classList.remove('active');
    document.getElementById('step1-content').classList.add('active');
  };

  // Inicialização do WebAssembly
  Module.onRuntimeInitialized = function () {
    console.log("WebAssembly pronto!");

    // === FUNÇÕES QUE CHAMAM O BACKEND ===
    // Gerar Chave Pública (usa generatePublicKey)
    window.generateKey = function () {
      const p = document.getElementById('prime1').value;
      const q = document.getElementById('prime2').value;
      const e = document.getElementById('exponent').value;

      if (!p || !q || !e) return alert("Preencha todos os campos!");

      try {
        const n = Module.ccall('generatePublicKey', 'string', ['string', 'string', 'string'], [p, q, e]);

        if (n.startsWith("KEY_ERROR")) throw new Error(n);

        document.getElementById('public-key').value = `(${e}, ${n})`;
        document.getElementById('private-key').value = `(${p}, ${q}, ${e})`;
        alert("Chave gerada com sucesso!");
      } catch (error) {
        alert(`Erro: ${error.message}`);
      }
    };

    // Criptografar (usa encryptMessage)
    window.encryptMessage = function () {
      const publicKey = document.getElementById('public-key').value;
      const message = document.getElementById('message').value;

      if (!publicKey || !message) return alert("Preencha todos os campos!");

      const match = publicKey.match(/\((\d+),\s*(\d+)\)/);
      if (!match) return alert("Formato inválido! Use (e, n)");

      try {
        const encrypted = Module.ccall(
          'encryptMessage',
          'string',
          ['string', 'string', 'string'],
          [message, match[2], match[1]] // (n, e)
        );
        document.getElementById('encrypted-output').textContent = encrypted;
      } catch (error) {
        alert(`Erro: ${error.message}`);
      }
    };

    // Descriptografar (usa decryptMessage)
    window.decryptMessage = function () {
      const privateKey = document.getElementById('private-key').value;
      let encryptedMsg = document.getElementById('message-decrypt').value.trim();

      if (!privateKey || !encryptedMsg) return alert("Preencha todos os campos!");

      const match = privateKey.match(/\((\d+),\s*(\d+),\s*(\d+)\)/);
      if (!match) return alert("Formato inválido! Use (p, q, e)");

      // Garante o espaço no final (requisito do backend)
      if (encryptedMsg.slice(-1) !== ' ') encryptedMsg += ' ';

      try {
        const decrypted = Module.ccall(
          'decryptMessage',
          'string',
          ['string', 'string', 'string', 'string'],
          [encryptedMsg, match[1], match[2], match[3]] // (p, q, e)
        );
        document.getElementById('decrypted-output').textContent = decrypted;
      } catch (error) {
        alert(`Erro: ${error.message}`);
      }
    };
  };
});