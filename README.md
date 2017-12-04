# Cshell - A very (very!) simple c shell 

This is based off the work of Enrico Franchi [seen here](https://web.archive.org/web/20170223203852/http://rik0.altervista.org/snippets/csimpleshell.html), 
with the added functionality of background processes. This is accessed by adding '&' as the last argument as so:

```
<user> $ [YOUR COMMAND] &
```

I've also slightly modified the code to use the [GNU readline library](https://cnswww.cns.cwru.edu/php/chet/readline/rltop.html), 
so that it can keep a history of your commands and use non-ascii characters such as the arrow keys (↑, ↓) to register as paging 
through your history.

That's about it! It's super simple.
