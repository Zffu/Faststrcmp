# Fast strcmp
A small library containing faster and better alternatives for `strcmp`.

## Benchmarks

| Method Used | Length of tested string |Time / op | Estimated strings / second | 
| --- | --- | --- | --- |
| faststrcmp (classic) | 1000 | 1.483ns | 674.4M/s |
| strcmp | 1000 | 9.587ns | 104.3M/s |
