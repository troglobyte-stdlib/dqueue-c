# Miok DQueue

## About

* * *

The DQueue being like a Stack, Queue is a linear structure which follows a
particular order in which the operations are performed. The order is First
In First Out (FIFO). The main data type that is returned will be the classic
c string or char array.

The design of the API has significant impact on its usage. The principle of
information hiding describes the role of programming interfaces as enabling
modular programming by hiding the implementation details of the modules so that
users of modules or packages need not understand the complexities inside the
modules implementation.

Modular programming is a software design technique that emphasizes separating
the functionality of a program into independent, interchangeable modules, such
that each contains everything necessary to execute only one aspect of the
desired functionality.

## Tooling information

* * *

Targeted audience we are building for is *Windows 10*, *MacOSX*, *ChromeOS*
and *Linux* users. This project uses [Meson](https://mesonbuild.com/) `0.60.0`
and newer, uses `c23` standards for initial implementation of the package. The
objective by far is usability, security, transparency, and lightweight, packages
for any if not most of your application development needs.

## Setup, Compile and Install

* * *

Using this package should be fairly simple just add the git wrap file
in your subprojects directory and include the dependency in your project.

```console
[wrap-git]
directory = miok-dqueue-c
url = https://github.com/miok-modules/dqueue-c.git
revision = main

[provide]
module = module_dqueue_dep
```


The next step should be to add the package to your Meson project:

```meson
module_dep = dependency('miko-dqueue-c')

executable('prog', 'main.c',
    dependencies : [module_dep])

```

And finally we setup, and compile the project just like normal.

## Usage of this package

* * *

Here is a simple sample application that should get you up and
running with using this library as soon as possible but to learn
more please view the API documentation thanks.

**Usage in C**:

```c
#include <stdio.h>
#include <stdlib.h>
#include <miok/dqueue.h>

//
// main is where all good examples start
//
int main(void)
{
    DeQueueOf *m_queue = miok_dqueue_create();
    if (miok_dqueue_its_empty(m_queue))
    {
        return EXIT_FAILURE;
    } // end if
    miok_dqueue_push(m_queue, "hello");
    miok_dqueue_push(m_queue, "crazy");
    miok_dqueue_push(m_queue, "world");

    while (miok_dqueue_not_empty(m_queue))
    {
        printf("%s ", miok_dqueue_peek(m_queue));
        miok_dqueue_pop(m_queue);
    } // end while
    miok_dqueue_erase(&m_queue);
    return EXIT_SUCCESS;
} // end of function main

```

## Join the developer community

* * *

You may find that the project has a community in which you
can keep up to date on the latest features, apps being developed and news. Simply done by
joining on [Reddit](https://www.reddit.com/r/miok/)

You may find that I have some platforms in which you can follow me and stay updated on what I???m working on.

- Reddit: [Michael Gene Brockus](https://www.reddit.com/u/Native_Oklatopian)
- facebook: [Michael Gene Brockus](https://michaelbrockus.medium.com/)
- linkedin: [Michael Gene Brockus](https://www.linkedin.com/in/michael-brockus)

Lastly don't forget to have a cup of virtual coffee, and happy coding. ???????
