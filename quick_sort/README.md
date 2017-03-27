# Quick sort

<b>Быстрая сортировка, сортировка Хоара</b> (англ. quicksort) - широко известный алгоритм сортировки, разработанный английским информатиком Чарльзом Хоаром во время его работы в МГУ в 1960 году.

Быстрый метод сортировки функционирует по принципу "разделяй и властвуй".
<ol>
  <li> Массив a[l ... r] типа T разбивается на два (возможно пустых) подмассива a[l ... q] и a[q + 1 ... r], таких, что каждый элемент a[l ... q] меньше или равен a[q], который в свою очередь, не превышает любой элемент подмассива a[q + 1 ... r]. Индекс вычисляется в ходе процедуры разбиения.</li>
   <li> Подмассивы a[l ... q] и a[q + 1 ... r] сортируются с помощью рекурсивного вызова процедуры быстрой сортировки.</li>
   <li> Поскольку подмассивы сортируются на месте, для их объединения не требуются никакие действия: весь массив a[l ... r] оказывается отсортированным. </li>
</ol>

<h2>Image</h2>
<img src="https://gist.githubusercontent.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/a733243cacfb6754b2aac781c475c0ebba08760e/qs.png">

<h2>Complexities</h2>
<div>
<table>
  <tr align="center">
    <td>Best</td>
    <td>Average</td>
    <td>Worst</td>
    <td>Space Complexity</td>
  </tr>
  <tr align="center">
    <td>Ω(n log(n))</td>
    <td>Θ(n log(n)) </td>
    <td>O(n^2)</td>
    <td>O(log(n))</td>
  </tr>
</table>
</div>

<h2>References</h2>
<ol>
  <li><a href="https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B2%D1%8B%D0%B1%D0%BE%D1%80%D0%BE%D0%BC">wikipedia.org</a></li>
  <li><a href="https://neerc.ifmo.ru/wiki/index.php?title=%D0%91%D1%8B%D1%81%D1%82%D1%80%D0%B0%D1%8F_%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0">neerc.ifmo.ru</a></li>
</ol>