void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(13, INPUT);

  Serial.begin(9600); // Initialize Serial Monitor with 9600 baud rate
}

void loop() {
  unsigned int a = pulseIn(13, HIGH, 180000000);
  int b = a / 100;
  int c = b % 10;
  int d = a / 1000;
  int e = d / 10;
  int f = d % 10;

  // Debugging: Print the raw values
  Serial.print("Pulse Duration: ");
  Serial.println(a);
  Serial.print("c: ");
  Serial.println(c);
  Serial.print("e: ");
  Serial.println(e);
  Serial.print("f: ");
  Serial.println(f);

  // Display the value of 'c'
  int i = c % 2;
  int j = (c / 2) % 2;
  int k = (c / 4) % 2;
  int l = (c / 8) % 2;

  digitalWrite(2, i);
  digitalWrite(3, j);
  digitalWrite(4, k);
  digitalWrite(5, l);
  digitalWrite(6, HIGH);
  digitalWrite(6, LOW);

  // Display the value of 'f'
  int m = f % 2;
  int n = (f / 2) % 2;
  int o = (f / 4) % 2;
  int p = (f / 8) % 2;

  digitalWrite(2, m);
  digitalWrite(3, n);
  digitalWrite(4, o);
  digitalWrite(5, p);
  digitalWrite(7, HIGH);
  digitalWrite(7, LOW);

  // Display the value of 'e'
  int q = e % 2;
  int r = (e / 2) % 2;
  int s = (e / 4) % 2;
  int t = (e / 8) % 2;

  digitalWrite(2, q);
  digitalWrite(3, r);
  digitalWrite(4, s);
  digitalWrite(5, t);
  digitalWrite(8, HIGH);
  digitalWrite(8, LOW);

  // Debugging: Print the binary values
  Serial.print("Binary c: ");
  Serial.print(i); Serial.print(j); Serial.print(k); Serial.println(l);

  Serial.print("Binary f: ");
  Serial.print(m); Serial.print(n); Serial.print(o); Serial.println(p);

  Serial.print("Binary e: ");
  Serial.print(q); Serial.print(r); Serial.print(s); Serial.println(t);

  delay(500); // Add a delay to avoid flooding the Serial Monitor
}
