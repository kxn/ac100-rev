// func rdmngr_set_multi_rate @ 00613ae8 size=24

undefined4 rdmngr_set_multi_rate(undefined1 param_1,undefined1 param_2)

{
  g_multi_rate = param_1;
  g_multi_rate_5g = param_2;
  return 0;
}

