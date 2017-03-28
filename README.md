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

<h2>Array Sorting Algorithms</h2>
<table>
  <tr>
    <th>Algorithm</th>
    <th colspan="3">Time Complexity</th>
    <th>Space Complexity</th>
  </tr>
  <tr>
    <th align="center"></th>
    <th>Best</th>
    <th>Average</th>
    <th>Worst</th>
    <th>Worst</th>
  </tr>
  <tr align="center">
    <th>Quicksort</th>
    <td>Ω(n log(n))</td>
    <td>Θ(n log(n))</td>
    <td>O(n^2)</td>
    <td>O(log(n))</td>
  </tr>
    <tr align="center">
    <th>Mergesort</th>
    <td>Ω(n log(n))</td>
    <td>Θ(n log(n))</td>
    <td>O(n log(n))</td>
    <td>O(n)</td>
  </tr>
    <tr align="center">
    <th>Timsort</th>
    <td>Ω(n)</td>
    <td>Θ(n log(n))</td>
    <td>O(n log(n))</td>
    <td>O(n)</td>
  </tr>
   <tr align="center">
    <th>Heapsort</th>
    <td>Ω(n log(n))</td>
    <td>Θ(n log(n))</td>
    <td>O(n log(n))</td>
    <td>O(1)</td>
  </tr>
   <tr align="center">
    <th>Bubble sort</th>
    <td>Ω(n)</td>
    <td>Θ(n^2)</td>
    <td>O(n^2)</td>
    <td>O(1)</td>
  </tr>
  <tr align="center">
    <th>Insertion sort</th>
    <td>Ω(n)</td>
    <td>Θ(n^2)</td>
    <td>O(n^2)</td>
    <td>O(1)</td>
  </tr>
  <tr align="center">
    <th>Selection sort</th>
    <td>Ω(n^2)</td>
    <td>Θ(n^2)</td>
    <td>O(n^2)</td>
    <td>O(1)</td>
  </tr>
  <tr align="center">
    <th>Tree sort</th>
    <td>Ω(n log(n))</td>
    <td>Θ(n log(n))</td>
    <td>O(n^2)</td>
    <td>O(n)</td>
  </tr>
    <tr align="center">
    <th>Shell sort</th>
    <td>Ω(n log(n))</td>
    <td>Θ(n(log(n))^2)</td>
    <td>O(n(log(n))^2)</td>
    <td>O(1)</td>
  </tr>
  </table>

<h2>Data structures</h2>
<table>
  <tr align="center">
    <th>Data Structure</th>
    <th colspan="8">Time Complexity</th>
    <th>Space Complexity</th>
  </tr>
  <tr align="center">
    <th></th>
    <th colspan="4">Average</th>
    <th colspan="4">Worst</th>
    <th>Worst</th>
  </tr>
  <tr align="center">
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
  <tr align="center">
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
  <tr align="center">
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
  <tr align="center">
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
  <tr align="center">
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
  <tr align="center">
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
  <tr align="center">
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
  <tr align="center">
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
    <tr align="center">
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
  <tr align="center">
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
  <tr align="center">
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