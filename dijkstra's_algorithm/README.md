# Dijkstra's algorithm

<b>Алгори́тм Де́йкстры</b> (англ. Dijkstra’s algorithm) — алгоритм на графах, изобретённый нидерландским учёным Эдсгером Дейкстрой в 1959 году. Находит кратчайшие пути от одной из вершин графа до всех остальных. Алгоритм работает только для графов без рёбер отрицательного веса.

<h2>Image</h2>
<img src="https://gist.githubusercontent.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/edfae4e1b614b80a51537f0af4d8887970f833ab/da.PNG">
<p><i>Graph from main.cpp</i></p>

<h2>Complexities</h2>
<div>
<table>
  <tr align="center">
    <td></td>
    <td>Average</td>
    <td>Worst</td>
    <td>Space Complexity</td>
  </tr>
  <tr align="center">
    <td>Using array</td>
    <td>O(|V|^2)</td>
    <td>O(|V|^2)</td>
    <td>O(|V|)</td>
  </tr>
    <tr align="center">
    <td>Using binary heap as priority queue</td>
    <td>O((|V| + |E|)log|V|)</td>
    <td>O((|V| + |E|)log|V|)</td>
    <td>O(|V|)</td>
  </tr>	 	
  </table>
  </div>
  
  <h2>References</h2>
  <a href="https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%94%D0%B5%D0%B9%D0%BA%D1%81%D1%82%D1%80%D1%8B">wikipedia.org</a>.