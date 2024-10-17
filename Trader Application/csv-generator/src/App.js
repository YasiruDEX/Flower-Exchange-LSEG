import React, { useState } from 'react';
import Papa from 'papaparse';
import './App.css'; // Import the new CSS file

function App() {
  const [orders, setOrders] = useState([]);
  const [formData, setFormData] = useState({
    clOrdID: '',
    instrument: '',
    side: '1', // Default to 'Buy'
    quantity: '',
    price: '',
  });

  const instruments = ['Rose', 'Lavender', 'Lotus', 'Tulip', 'Orchid']; // List of instruments

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData({ ...formData, [name]: value });
  };

  const handleAddOrder = () => {
    setOrders([...orders, formData]);
    setFormData({ clOrdID: '', instrument: '', side: '1', quantity: '', price: '' });
  };

  const generateCSV = () => {
    const csvData = [
      ['Cl. Ord. ID', 'Instrument', 'Side', 'Quantity', 'Price'],
      ...orders.map(order => [
        order.clOrdID,
        order.instrument,
        order.side === '1' ? 'Buy' : 'Sell',
        order.quantity,
        order.price,
      ]),
    ];

    const csv = Papa.unparse(csvData);
    const blob = new Blob([csv], { type: 'text/csv;charset=utf-8;' });
    const link = document.createElement('a');
    const url = URL.createObjectURL(blob);
    link.setAttribute('href', url);
    link.setAttribute('download', 'order.csv');
    link.style.visibility = 'hidden';
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
  };

  return (
    <div className="container">
      <header className="header">
        <h1>Flower Exchange App Trader Application</h1>
      </header>

      <div className="form-container">
        <h2>Order Entry</h2>
        <div className="form-inputs">
          <input
            type="text"
            name="clOrdID"
            placeholder="Cl. Ord. ID"
            value={formData.clOrdID}
            onChange={handleChange}
            className="input"
          />
          <select name="instrument" value={formData.instrument} onChange={handleChange} className="input">
            <option value="">Select Instrument</option>
            {instruments.map((instrument) => (
              <option key={instrument} value={instrument}>
                {instrument}
              </option>
            ))}
          </select>
          <select name="side" value={formData.side} onChange={handleChange} className="input">
            <option value="1">Buy</option>
            <option value="2">Sell</option>
          </select>
          <input
            type="number"
            name="quantity"
            placeholder="Quantity"
            value={formData.quantity}
            onChange={handleChange}
            className="input"
          />
          <input
            type="number"
            step="0.01"
            name="price"
            placeholder="Price"
            value={formData.price}
            onChange={handleChange}
            className="input"
          />
          <button onClick={handleAddOrder} className="button">
            Add Order
          </button>
        </div>

        <button onClick={generateCSV} className="button download-button">
          Download CSV
        </button>
      </div>

      <h3>Current Orders</h3>
      <table className="order-table">
        <thead>
          <tr>
            <th>Cl. Ord. ID</th>
            <th>Instrument</th>
            <th>Side</th>
            <th>Quantity</th>
            <th>Price</th>
          </tr>
        </thead>
        <tbody>
          {orders.map((order, index) => (
            <tr key={index}>
              <td>{order.clOrdID}</td>
              <td>{order.instrument}</td>
              <td>{order.side === '1' ? 'Buy' : 'Sell'}</td>
              <td>{order.quantity}</td>
              <td>{order.price}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default App;
