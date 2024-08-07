document.addEventListener('DOMContentLoaded', () => {
    fetch('output.txt')
        .then(response => response.text())
        .then(text => {
            const lines = text.trim().split('\n');

            const intro_text = lines[0];
            const table_lines = [];
            let i = 1;

            // finding the end of the table
            while (i < lines.length && !lines[i].startsWith('Average')) {
                table_lines.push(lines[i]);
                i++;
            }
            
            const additional_text = lines.slice(i).join('\n');

            // get intro text
            document.getElementById('algorithm-name').innerText = intro_text;

            if (table_lines.length > 0) {
                const headers = table_lines[0].split(',');
                const thead = document.querySelector('#data-table thead');
                const tbody = document.querySelector('#data-table tbody');

                // create table headers
                const headerRow = document.createElement('tr');
                headers.forEach(header => {
                    const th = document.createElement('th');
                    th.textContent = header.trim();
                    headerRow.appendChild(th);
                });
                thead.appendChild(headerRow);

                // create table rows
                table_lines.slice(1).forEach(row => {
                    const columns = row.split(',');
                    const tr = document.createElement('tr');

                    columns.forEach(col => {
                        const td = document.createElement('td');
                        td.textContent = col.trim();
                        tr.appendChild(td);
                    });

                    tbody.appendChild(tr);
                });
            }

            // get additional text
            document.getElementById('parameter-average').innerText = additional_text;
        })
        .catch(error => {
            console.error('Could not find the file:', error);
        });
});
