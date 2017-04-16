# Selection sort

<b>Сортировка выбором</b> (Selection sort) — алгоритм сортировки. Может быть как устойчивый, так и неустойчивый.

Шаги алгоритма:
<ol>
  <li> Находим номер минимального значения в текущем списке </li>
  <li> Производим обмен этого значения со значением первой неотсортированной позиции (обмен не нужен, если минимальный элемент уже находится на данной позиции) </li>
  <li> Tеперь сортируем хвост списка, исключив из рассмотрения уже отсортированные элементы </li>
</ol>

<h2>Image</h2>
<img src="https://gist.githubusercontent.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/885491611155e313aa040fc61347f268ba13efb9/ss.png">

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
    <td>Ω(n^2)</td>
    <td>O(n^2)</td>
    <td>O(n^2)</td>
    <td>O(1)</td>
  </tr>
</table>
</div>

<h2>References</h2>
<a href="https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B2%D1%8B%D0%B1%D0%BE%D1%80%D0%BE%D0%BC">wikipedia.org</a>.
