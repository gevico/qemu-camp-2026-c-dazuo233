#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int parse_url(const char* url) {
    int err = 0;

    const char *query = strchr(url, '?');
    if (!query) {
        err = 1;
        goto exit;
    }
    query++;

    char *query_copy = strdup(query);
    if (!query_copy) {
        err = 2;
        goto exit;
    }

    char *pair = strtok(query_copy, "&");
    while (pair != NULL) {
        char *eq = strchr(pair, '=');
        if (eq) {
            *eq = '\0';
            printf("key = %s, value = %s\n", pair, eq + 1);
        }
        pair = strtok(NULL, "&");
    }

    free(query_copy);

exit:
    return err;
}

int main() {
    const char* test_url = "https://cn.bing.com/search?name=John&age=30&city=New+York";

    printf("Parsing URL: %s\n", test_url);
    printf("Parameters:\n");

    parse_url(test_url);

    return 0;
}
