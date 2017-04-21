# Persistent stack

<p>Для реализации полностью персистентного стека будем использовать следующий подход:</p>
<ol>
  <li>Каждый узел стека – это версия стека.</li>
  <li>Узел стека, помимо данных, будет хранить указатель на предыдущий узел. Тогда для восстановления всего стека надо знать только его вершину.</li>
  <li>Будем хранить вершины всех версий стека в массиве. Тогда i-ому номеру вершины в массиве будет соответствовать i-ая версия стека.</li>
</ol>

<p>
<b>Push</b>
<ol>
  <li>Создать узел стека.</li>
  <li>Указатель на предыдущий узел направить на вершину стека, в который осуществляем вставку. </li>
  <li>Узел поместить в массив вершин.</li>
</ol>
<code>push(2, 114);</code>
<img src="https://gist.githubusercontent.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/f415edc2db2203735c269e8d3397b70b111803f6/pushps.jpg">

<b>Pop</b>
<ol>
  <li>Создать копию новой вершины.</li>
  <li>Указатель направить на предыдущий элемент.</li>
  <li>Узел поместить в массив вершин.</li>
</ol>
<code>pop(2);</code>
<img src="https://gist.githubusercontent.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/18cfb67d509e42fe6dea513107eb2bf7472ac6c8/popps(1).jpg">
</p>

<h2>Пример:</h2>
<p>
Операции без указания конкретной версии стека выполняются для последнего полученного стека.
<pre>
<code>
    persistent_stack.push(17);
    persistent_stack.push(27); 
    persistent_stack.push(4);
    persistent_stack.push(23);
    persistent_stack.pop();
</code>
</pre>
</p>
<p>После следующих операций стек примет вид:</p>
<img src="https://gist.githubusercontent.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/f85d9c4e445961494fe520ba63cd8cceae3b9421/ps1.jpg">

<p>Для того, чтобы обратиться к конкретной версии стека, будем использовать следующий синтаксис: 
<ol>
  <li><code>push(i, x)</code></li>
  <li><code>pop(i)</code></li>
</ol>
 <p>где i - номер стека, x - значение.<br>
 Тогда:
 <pre>
<code>
    persistent_stack.push(3, 47); // push 47 to stack number 3
    persistent_stack.push(5, 74); // push 74 to stack number 74
    persistent_stack.pop(3);      // pop top element of stack number 3
</code>
</pre>
<img src="https://gist.githubusercontent.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/f85d9c4e445961494fe520ba63cd8cceae3b9421/ps2.jpg">
</p>