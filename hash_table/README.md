# Hash table

<b>Хеш-таблица</b> - структура данных, реализующая интерфейс <a href="https://ru.wikipedia.org/wiki/%D0%90%D1%81%D1%81%D0%BE%D1%86%D0%B8%D0%B0%D1%82%D0%B8%D0%B2%D0%BD%D1%8B%D0%B9_%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2">ассоциативного массива</a>, а именно, она позволяет хранить пары (ключ, значение) и выполнять три операции: операцию добавления новой пары, операцию поиска и операцию удаления пары по ключу.

Важное свойство хеш-таблиц состоит в том, что, при некоторых разумных допущениях, все три операции (поиск, вставка, удаление элементов) в среднем выполняются за время O(1). Но при этом не гарантируется, что время выполнения отдельной операции мало́. Это связано с тем, что при достижении некоторого значения коэффициента заполнения необходимо осуществлять перестройку индекса хеш-таблицы: увеличить значение размера массива H и заново добавить в пустую хеш-таблицу все пары.

<h2>Разрешение коллизий</h2>
<ol>
  <li>Метод цепочек</li>
  <img src="https://gist.githubusercontent.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/7e9f57c18287d7f968d44151d7a9159de9b1f498/htchain.png">
  <li>Открытая адресация</li>
  <img src="https://gist.githubusercontent.com/deniskovalchuk/ffcff1289e8b0209d47fb7336dfce5c0/raw/7e9f57c18287d7f968d44151d7a9159de9b1f498/htline.png">
</ol>

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
    <td>N/A</td>
    <td>N/A</td>
  </tr>	 	
  <tr>
    <td>Search</td>
    <td>O(1)</td>
    <td>O(n)</td>
  </tr>
    <tr>
    <td>Insertion</td>
    <td>O(1)</td>
    <td>O(n)</td>
  </tr>
    <tr>
    <td>Deletion</td>
    <td>O(1)</td>
    <td>O(n)</td>
  </tr>
</table>
</div>    
  
<h2>References</h2>
<a href="https://ru.wikipedia.org/wiki/%D0%A5%D0%B5%D1%88-%D1%82%D0%B0%D0%B1%D0%BB%D0%B8%D1%86%D0%B0">wikipedia.org</a>.