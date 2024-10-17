import graphviz

def generate_flowchart():
    # Create a new directed graph
    dot = graphviz.Digraph(comment='CSV Order Processing')

    # Define nodes
    dot.node('A', 'Start')
    dot.node('B', 'Read CSV File')
    dot.node('C', 'Validate Order')
    dot.node('D', 'Invalid Order: Write to CSV (Reject)')
    dot.node('E', 'Valid Order: Add to Buy/Sell Table')
    dot.node('F', 'Sort Buy Table (Descending by Price)')
    dot.node('G', 'Sort Sell Table (Ascending by Price)')
    dot.node('H', 'Attempt to Match Orders')
    dot.node('I', 'Order Matched: Mark Fill or PFill')
    dot.node('J', 'No Match: Keep in Table')
    dot.node('K', 'Write Execution Time to CSV')
    dot.node('L', 'End')

    # Define edges
    dot.edge('A', 'B', 'Start Process')
    dot.edge('B', 'C', 'Read Order')
    dot.edge('C', 'D', 'Invalid Order')
    dot.edge('C', 'E', 'Valid Order')
    dot.edge('E', 'F', 'Add to Buy/Sell Table')
    dot.edge('F', 'G', 'Sort Buy Table')
    dot.edge('G', 'H', 'Sort Sell Table')
    dot.edge('H', 'I', 'Match Found')
    dot.edge('H', 'J', 'No Match Found')
    dot.edge('I', 'K', 'Write Matched Order to CSV')
    dot.edge('J', 'K', 'Write Unmatched Order to CSV')
    dot.edge('K', 'L', 'Finish Process')

    # Save and render the flowchart to a file
    dot.render('csv_order_processing_flowchart', format='png', view=True)

# Generate the flowchart
generate_flowchart()
