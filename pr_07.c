#define isdigit(c) ((c) >= '0' && (c) <= '9')

#ifdef TEST
while (isdigit(*--jext)) {
  if (*jext != '9') {
    (*jext)++;
    break;
  }
  *jext = '0';
}
#endif
