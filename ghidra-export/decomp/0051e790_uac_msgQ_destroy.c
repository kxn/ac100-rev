// func uac_msgQ_destroy @ 0051e790 size=40

void uac_msgQ_destroy(char *param_1)

{
  if (param_1 != (char *)0x0) {
    mq_unlink(param_1);
    return;
  }
  return;
}

