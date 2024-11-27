# Fast strcmp
A small library containing faster and better alternatives for `strcmp`.

## Benchmarks

| Method Used | Length of tested string |Time / op | Estimated strings / second | 
| --- | --- | --- | --- |
| faststrcmp (classic) | 100 | 1.483ns | 674.4M/s |
| faststrcmp (classic) | 1000 | 1.586ns | 630.5M/s |
| strcmp | 100 | 9.587ns | 104.3M/s |
| strcmp | 1000 | 104.248ns | 9.6M/s | 
