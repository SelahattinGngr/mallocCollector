# Malloc Collector

Bu, C dilinde yazılmış basit bir malloc toplayıcıdır. Dinamik olarak ayrılan belleği yönetmenizi sağlar ve temel bir çöp toplama işlevi sunar.

## Nasıl Kullanılır

### 1. mallocCollector.h'i Projeye Dahil Et

```c
#include "mallocCollector.h"
```

### 2. Malloc Collector'ü Başlatın

```C
t_mallocCollector *mc = malloc_start();
```

Bu fonksiyon malloc toplayıcıyı başlatır ve toplayıcı yapısının bir işaretçisini döndürür.

### 3. new_malloc Kullanarak Bellek Ayırma

```C
char *a = (char *)new_malloc(mc, sizeof(char) * 20);
```

Bellek ayırmak için new_malloc fonksiyonunu kullanın. Bu fonksiyon, ayrılan belleğin bir işaretçisini döndürür. Bellek otomatik olarak malloc toplayıcı tarafından izlenir.

### 4. delete_malloc Kullanarak Bellek Serbest Bırakma (Opsiyonel)

Bellek serbest bırakma işlemi için delete_malloc fonksiyonu kullanılabilir. Ancak, bu fonksiyonu kullanmadan da programınız çalışabilir.

```C
delete_malloc(mc, a);
```

Ayrılan belleği serbest bırakmak için delete_malloc fonksiyonunu çağırın. Fonksiyon, malloc toplayıcı işaretçisi (mc) ve serbest bırakılacak bellek işaretçisini alır.

delete_malloc fonksiyonu kullanılmazsa, ayrılan bellek otomatik olarak end_malloc fonksiyonu çağrıldığında serbest bırakılacaktır.

### 5. Malloc Toplayıcıyı Sonlandırma

```C
end_malloc(mc);
```

Malloc toplayıcıyı kullanmayı bitirdiğinizde, tüm kalan belleği serbest bırakmak ve malloc toplayıcı kaynaklarını serbest bırakmak için end_malloc fonksiyonunu çağırın.

## Örnek

```C
#include "mallocCollector.h"
#include <stdio.h>

int main()
{
    t_mallocCollector *mc = malloc_start();

    char *a = (char *)new_malloc(mc, sizeof(char) * 20);
    char *b = (char *)new_malloc(mc, sizeof(char) * 20);
    char *c = (char *)new_malloc(mc, sizeof(char) * 20);
    char *d = (char *)new_malloc(mc, sizeof(char) * 20);
    char *e = (char *)new_malloc(mc, sizeof(char) * 20);
    char *f = (char *)new_malloc(mc, sizeof(char) * 20);
    char *g = (char *)new_malloc(mc, sizeof(char) * 20);
    char *h = (char *)new_malloc(mc, sizeof(char) * 20);

    // ayrılan belleği kullan

    // opsiyoneldir, anlık yer açıp silmeniz gereken yerde kullanılması tavsiye edilir
    delete_malloc(mc, b);

    // belleği kullanmaya devam et

    end_malloc(mc);
    return 0;
}
```

Bu örnek, malloc toplayıcıyı başlatma, bellek ayırma, belleği serbest bırakma ve malloc toplayıcıyı sonlandırma işlemlerini göstermektedir.
