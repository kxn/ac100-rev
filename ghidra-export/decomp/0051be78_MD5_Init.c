// func MD5_Init @ 0051be78 size=60

int MD5_Init(MD5_CTX *c)

{
  c->B = 0;
  c->A = 0;
  c->C = 0x67452301;
  c->D = 0xefcdab89;
  c->Nl = 0x98badcfe;
  c->Nh = 0x10325476;
  return 0x10325476;
}

