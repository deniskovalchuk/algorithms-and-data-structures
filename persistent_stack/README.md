# Persistent stack

<b>Персистентные структуры данных</b> (англ. persistent data structure) — это структуры данных, которые сохраняют все свои состояния и позволяют в любой момент времени обратиться к ним.

Уровни персистентности:
<ol>
  <li>Частичная (англ. partial)</li>
  <li>Полная (англ. full)</li>
  <li>Конфлюэнтная (англ. confluent)</li>
  <li>Фунциональная (англ. functional)</li>
</ol>

<h2>Персистентный стек</h2>
<p>Для реализации полностью персистентного стека будем использовать следующий подход:</p>
<ol>
  <li>Первый элемент будет фиктивным и содержаться в стеке с номером 0.</li>
  <li>Для каждого узла будем хранить указатель на предыдущий узел. Тогда для востановления всего стека надо знать только его вершину. </li>
  <li>Будем хранить все верхние узлы.</li>
</ol>

<h2>Пример:</h2>
<p>
Операции без указания конкретного номера стека будут выполняться для последнего полученного стека.
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

<h2>References</h2>
<ol>
  <li><a href="https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D0%B5%D1%80%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BD%D1%82%D0%BD%D1%8B%D0%B5_%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D1%8B_%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D1%85">neerc.ifmo.ru</a></li>
</ol>