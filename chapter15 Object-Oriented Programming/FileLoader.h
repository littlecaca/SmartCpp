#include <sstream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <iostream>

#ifndef FILELOADER_H
#define FILELOADER_H

class FileLoader
{
public:
    virtual std::shared_ptr<std::vector<std::string>> load(std::ifstream &) const = 0;
    virtual ~FileLoader() {}
    const std::string sep;
protected:
    FileLoader(const std::string &seprate) : sep(seprate) {}
};

class LineLoader : public FileLoader 
{
public:
    LineLoader() : FileLoader("line") {}
    std::shared_ptr<std::vector<std::string>> load(std::ifstream &) const override;
};

std::shared_ptr<std::vector<std::string>> LineLoader::load(std::ifstream &infile) const
{
    std::string line;
    auto file = std::make_shared<std::vector<std::string>>();
    while (getline(infile, line)) 
    {
        file->push_back(line);
    }
    return file;
}

class SentenceLoader : public FileLoader
{
public:
    SentenceLoader() : FileLoader("sentence") {}
    std::shared_ptr<std::vector<std::string>> load(std::ifstream &) const override;
};

std::shared_ptr<std::vector<std::string>> SentenceLoader::load(std::ifstream &infile) const
{
    std::string sentence, line;
    auto file = std::make_shared<std::vector<std::string>>();
    std::string::size_type edge;
    while (getline(infile, line))
    {
        while ((edge = line.find_first_of('.')) != std::string::npos)
        {
            sentence.append(line, 0, edge + 1);
            file->push_back(sentence);
            sentence.clear();
            auto not_space = line.find_first_not_of(' ', edge + 1);
            line = line.substr(not_space == std::string::npos ? edge + 1 : not_space);
        }
        sentence.append(line);
        // need to add a space to substitute line break
        if (infile)
            sentence.append(" ");
    }
    if (!sentence.empty())
    {
        file->push_back(sentence);
    }
    return file;
}

#endif