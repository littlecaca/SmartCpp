class Base {
  public:
	int public_mem;

  protected:
	int prot_mem;

  private:
	int priv_mem;
};

class Pub_Derv : public Base {
	void memfcn(Base &b) { b = *this; };
};

class Priv_Derv : private Base {
	void memfcn(Base &b) { b = *this; };
};

class Prot_Derv : protected Base {
	void memfcn(Base &b) { b = *this; };
};

class Derived_from_Public : public Pub_Derv {
	void memfcn(Base &b) { b = *this; };
};

class Derived_from_Prot : public Prot_Derv {
	void memfcn(Base &b) { b = *this; };
};

class Derived_from_Priv : public Priv_Derv {
	// void memfcn(Base &b) { b = *this; };
};

int main(int argc, char const *argv[]) {
	Pub_Derv d1;
	Base *p = &d1;
	Priv_Derv d2;
	// p = &d2;
	Prot_Derv d3;
	// p = &d3;
	Derived_from_Public d4;
	p = &d4;
	Derived_from_Prot d5;
	// p = &d5;
	Derived_from_Priv d6;
	// p = &d6;

    
	return 0;
}
