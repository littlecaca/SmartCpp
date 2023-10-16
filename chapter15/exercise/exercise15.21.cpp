#include <string>

class Media {
  public:
    int id;
};

class Picture : public Media {
  public:
    virtual char*get_content() = 0;
    virtual void test() = 0;
  protected:
    std::string encode;
};

class Gif : public Picture {
  private:
    void test() override;
    char *get_content() override final;
};

class Tiff : public Picture {
  public:
    char *get_content() override final;
};

class Jpeg : public Picture {
  public:
    char *get_content() override final;
};

class Bmp : public Picture { 
  public:
    char *get_content() override final;
};

