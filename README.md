# Fast strcmp
A small library containing faster and better alternatives for `strcmp`.

## Benchmarks

| Method Used | Length of tested string |Time / op | Estimated strings / second | 
| --- | --- | --- | --- |
| faststrcmp (classic) | 100 | 1.483ns | 674.4M/s |
| faststrcmp (classic) | 1000 | 1.586ns | 630.5M/s |
| faststrcmp (classic) | 10000 | 1.630ns | 613.5M/s |
| faststrcmp (classic) | 100000 | 1.702ns | 587.6M/s |
| faststrcmp (classic) | 1000000 | 1.549ns | 645.5M/s |
| strcmp | 100 | 9.587ns | 104.3M/s |
| strcmp | 1000 | 104.248ns | 9.6M/s | 
| strcmp | 10000 | 748.097ns | 1.3M/s |
| strcmp | 100000 | 7775.556ns | 128.6k/s |
| strcmp | 1000000 | 80470.809ns | 12.4k/s |

