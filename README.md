# Complexities

<table>
  <tr>
    <th>Оператор сравнения асимптотических оценок</th>
    <th>Оператор сравнения чисел</th>
  </tr>
  <tr>
    <td>Алгоритм является o( что-то )</td>
    <td>Число &lt; чего-то</td>
  </tr>
  <tr>
    <td>Алгоритм является O( что-то )</td>
    <td>Число &lt;= чего-то</td>
  </tr>
    <tr>
    <td>Алгоритм является Θ( что-то )</td>
    <td>Число = чего-то</td>
  </tr>
    <tr>
    <td>Алгоритм является Ω( что-то )</td>
    <td>Число &gt;= чего-то</td>
  </tr>
  <tr>
    <td>Алгоритм является ω( что-то )</td>
    <td>Число &gt; чего-то</td>
  </tr>
</table>

<h2>Data structures</h2>
<table>
  <tr>
    <th>Data Structure</th>
    <th colspan="8">Time Complexity</th>
    <th>Space Complexity</th>
  </tr>
  <tr>
    <th></th>
    <th colspan="4">Average</th>
    <th colspan="4">Worst</th>
    <th>Worst</th>
  </tr>
  <tr>
    <th></th>
    <th>Access</th>
    <th>Search</th>
    <th>Insertion</th>
    <th>Deletion</th>
    <th>Access</th>
    <th>Search</th>
    <th>Insertion</th>
    <th>Deletion</th>
    <th></th>
  </tr>
  <tr>
    <th>Array</th>
    <td>O(1)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(1)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
  </tr>
  <tr>
    <th>Stack</th>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(n)</td>
  </tr>
  <tr>
    <th>Queue</th>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(n)</td>
  </tr>
  <tr>
    <th>Singly-Linked List</th>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(n)</td>
  </tr>
  <tr>
    <th>Doubly-Linked List</th>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(n)</td>
  </tr>
  <tr>
    <th>Skip List</th>
    <td>O(log(n))</td>
    <td>O(log(n))</td>
    <td>O(log(n))</td>
    <td>O(log(n))</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n log(n))</td>
  </tr>
  <tr>
    <th>Hash table</th>
    <td>N/A</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>N/A</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
  </tr>
    <tr>
    <th>Binary Search Tree</th>
    <td>Θ(log(n))</td>
    <td>Θ(log(n))</td>
    <td>Θ(log(n))</td>
    <td>Θ(log(n))</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
    <td>O(n)</td>
  </tr>
  <tr>
    <th>Red-Black Tree</th>
    <td>Θ(log(n))</td>
    <td>Θ(log(n))</td>
    <td>Θ(log(n))</td>
    <td>Θ(log(n))</td>
    <td>O(log(n))</td>
    <td>O(log(n))</td>
    <td>O(log(n))</td>
    <td>O(log(n))</td>
    <td>O(n)</td>
  </tr>
  <tr>
    <th>B-Tree</th>
    <td>Θ(log(n))</td>
    <td>Θ(log(n))</td>
    <td>Θ(log(n))</td>
    <td>Θ(log(n))</td>
    <td>O(log(n))</td>
    <td>O(log(n))</td>
    <td>O(log(n))</td>
    <td>O(log(n))</td>
    <td>O(n)</td>
  </tr>
</table>

<h2>References</h2>
  <ol>
    <li><i>Введение в анализ сложности алгоритмов (часть 1).</i> Available at: <a href="https://habrahabr.ru/post/196560/">https://habrahabr.ru/post/196560</a></li>
    <li><i>Введение в анализ сложности алгоритмов (часть 2).</i> Available at: <a href="https://habrahabr.ru/post/195482/">https://habrahabr.ru/post/195482/</a></li>
    <li><i>Введение в анализ сложности алгоритмов (часть 3).</i> Available at: <a href="https://habrahabr.ru/post/195996/">https://habrahabr.ru/post/195996/</a></li>
    <li><i>Введение в анализ сложности алгоритмов (часть 4).</i> Available at: <a href="https://habrahabr.ru/post/196226/">https://habrahabr.ru/post/196226/</a></li>
    <li><i>Big-O Algorithm Complexity Cheat Sheet.</i> Available at: <a href="http://bigocheatsheet.com">http://bigocheatsheet.com</a></li>
    <li><i>Знай сложности алгоритмов.</i> Available at: <a href="https://habrahabr.ru/post/188010">https://habrahabr.ru/post/188010</a></li>
    <li><i>Оценка сложности алгоритмов.</i> Available at: <a href="https://habrahabr.ru/post/104219/">https://habrahabr.ru/post/104219</a></li>  
  </ol>
