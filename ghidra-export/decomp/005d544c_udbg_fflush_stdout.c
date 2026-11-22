// func udbg_fflush_stdout @ 005d544c size=44

void udbg_fflush_stdout(void)

{
  fflush(stdout);
  fflush(stderr);
  return;
}

