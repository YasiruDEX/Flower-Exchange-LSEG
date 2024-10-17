<h1>🌸 Flower Exchange Project</h1>

<p>
  The <strong>Flower Exchange Project</strong> is a trading platform for buying and selling flowers, built as part of the LSEG C++ Workshop Series. It includes a C++ back-end for processing orders and a <strong>React</strong>-based front-end for generating orders in CSV format.
</p>

<h2>🚀 Getting Started</h2>

<ol>
  <li>Clone the repository to your local machine:</li>
  <pre><code>git clone &lt;repository_url&gt; </code></pre>
  
  <li>Run the Trader and Exchange applications to simulate placing and matching orders.</li>
</ol>

<h2>🔢 Input and Output</h2>

<ul>
  <li><strong>Input:</strong> Orders are submitted in CSV format (<code>orders.csv</code>) containing fields like Order ID, Client Order ID, Instrument, Side (Buy/Sell), Quantity, and Price.</li>
  <li><strong>Output:</strong> The <code>execution_rep.csv</code> file is generated, which shows the status of each order (e.g., New, Partial Fill, Fill, Reject).</li>
</ul>

<h2>⚙️ Implementation Details</h2>

<ul>
  <li>Order validation checks for missing fields, valid flower types, side (buy/sell), valid quantities, and prices. Rejected orders are noted with reasons.</li>
  <li>Orders are sorted and matched based on price and quantity. The system supports full and partial executions of orders.</li>
  <li>An optimized version is available for handling single flower type orders, reducing computation overhead for better performance.</li>
  <li>The execution time is logged in the output for performance analysis.</li>
</ul>

<h2>🎨 React Front-End</h2>

<p>
  A separate front-end interface is built using <strong>React</strong> to allow users (traders) to submit buy and sell orders. The front-end generates the <code>orders.csv</code> file, which is then processed by the Exchange Application.
</p>

<h3>📋 Instructions to Run the React App</h3>

<ol>
  <li>Clone the front-end repository:</li>
  <pre><code>git clone &lt;repository_url&gt;</code></pre>
  
  <li>Navigate to the project directory:</li>
  <pre><code>cd &lt;project_directory&gt;</code></pre>
  
  <li>Install the dependencies:</li>
  <pre><code>npm install</code></pre>
  
  <li>Start the React development server:</li>
  <pre><code>npm start</code></pre>
  
  <li>Open your browser and navigate to <code>http://localhost:3000</code> to access the Trader Application.</li>
  
  <li>Submit orders through the interface, and the <code>orders.csv</code> file will be generated automatically.</li>
</ol>
