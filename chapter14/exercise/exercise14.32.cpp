#include "exercise14.30.h"
#include <iostream>


class PPStrBlob {
    StrBlobPtr *pp;
  public:
    // Constructors
    PPStrBlob() : pp(nullptr) {}
    PPStrBlob(StrBlobPtr &p) : pp(&p) {}

    // Member access and Arrow operators
    StrBlobPtr &operator*();
    StrBlobPtr &operator->();
};

StrBlobPtr &PPStrBlob::operator*() {
    return *pp;
}

StrBlobPtr &PPStrBlob::operator->() {
    return operator*();
}

int main(int argc, char const *argv[])
{
    StrBlob blob({"yes", "we", "are"});
    StrBlobPtr pBlob(blob);
    PPStrBlob ppBlob(pBlob);

    std::cout << ppBlob->back() << std::endl;
    return 0;
}
