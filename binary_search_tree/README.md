# Binary search tree

<b>Двоичное дерево поиска</b> (англ. binary search tree, BST) — это <a href="https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D0%BE%D0%B5_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE">двоичное дерево</a>, для которого выполняются следующие дополнительные условия (свойства дерева поиска):
<ul>
<li>Оба поддерева — левое и правое — являются двоичными деревьями поиска.</li>
  <li>У всех узлов левого поддерева произвольного узла X значения ключей данных меньше, нежели значение ключа данных самого узла X.</li>
  <li>У всех узлов правого поддерева произвольного узла X значения ключей данных больше либо равно, нежели значение ключа данных самого узла X.</li>
</ul>

<h2>Image</h2>
<img src="https://gist.github.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/7e1f5b978eefbe81285e6adc3811d76412e0e165/bt.png">

<h2>Complexities</h2>
<div>
<table>
  <tr>
    <td></td>
    <td>Average</td>
    <td>Worst</td>
  </tr>
  <tr>
    <td>Space Complexity</td>
    <td>O(n)</td>
    <td>O(n)</td>
  </tr>
    <tr>
    <td>Access</td>
    <td>O(log n)</td>
    <td>O(n)</td>
  </tr>	 	
  <tr>
    <td>Search</td>
    <td>O(log n)</td>
    <td>O(n)</td>
  </tr>
    <tr>
    <td>Insertion</td>
    <td>O(log n)</td>
    <td>O(n)</td>
  </tr>
    <tr>
    <td>Deletion</td>
    <td>O(log n)</td>
    <td>O(n)</td>
  </tr>
  </table>
  </div>
  
  <h2>References</h2>
  <a href="https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D0%BE%D0%B5_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA%D0%B0">wikipedia.org</a>.
