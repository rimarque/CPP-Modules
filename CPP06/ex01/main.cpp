#include "includes/Serializer.hpp"
#include "includes/MyException.hpp"

int    null_data_test(bool detail){
    Data        *expected_result = NULL;
    uintptr_t   converted_result;
    Data        *actual_result = NULL;

    converted_result = Serializer::serialize(expected_result);
    actual_result = Serializer::deserialize(converted_result);
    if(expected_result == actual_result){
        if(detail == true){
            std::cout << GREEN << "Null data test: " << RESET <<
            "Expected result equal to actual result: " << expected_result 
            << " = " << actual_result << std::endl;
            std::cout << std::endl << "<---------------------------------------------->\n\n";
        }
        return 0;
    }
    if (detail == true){
        std::cout << RED << "Null data test: Wrong output!\n";
        std::cout << std::endl << "<---------------------------------------------->\n\n";
    }
    return 1;
}

int    new_data_test(bool detail){
    Data        *expected_result = new Data;
    uintptr_t   converted_result;
    Data        *actual_result = NULL;

    converted_result = Serializer::serialize(expected_result);
    actual_result = Serializer::deserialize(converted_result);
    if(expected_result == actual_result){
        if(detail == true){
            std::cout << GREEN << "New data test: " << RESET <<
            "Expected result equal to actual result: " << expected_result 
            << " = " << actual_result << std::endl;
            std::cout << std::endl << "<---------------------------------------------->\n\n";
        }
        delete expected_result;
        return 0;
    }
    if(detail == true){
        std::cout << RED << "New data test: Wrong output!\n";
        std::cout << std::endl << "<---------------------------------------------->\n\n";
    }
    delete expected_result;
    return 1;
}

int    init_data_test(bool detail){
    Data        *expected_result = new Data;
    uintptr_t   converted_result;
    Data        *actual_result = NULL;

    expected_result->data = 1;
    converted_result = Serializer::serialize(expected_result);
    actual_result = Serializer::deserialize(converted_result);
    if(expected_result == actual_result){
        if(detail == true){
            std::cout << GREEN << "Init data test: " << RESET <<
            "Expected result equal to actual result: " << expected_result 
            << " = " << actual_result << std::endl;
            std::cout << "Expected result data: " << expected_result->data << std::endl;
            std::cout << "Actual result data: " << actual_result->data << std::endl;  
            std::cout << std::endl << "<---------------------------------------------->\n\n";
        }
        delete expected_result;
        return 0;
    }
    if(detail == true){
        std::cout << RED << "Init data test: Wrong output!\n";
        std::cout << std::endl << "<---------------------------------------------->\n\n";
    }
    delete expected_result;
    return 1;
}

int    bigint_data_test(bool detail){
    Data        *expected_result = new Data;
    uintptr_t   converted_result;
    Data        *actual_result = NULL;

    expected_result->data = -579278389;
    converted_result = Serializer::serialize(expected_result);
    actual_result = Serializer::deserialize(converted_result);
    if(expected_result == actual_result){
        if( detail == true){
            std::cout << GREEN << "Big int data test: " << RESET <<
            "Expected result equal to actual result: " << expected_result 
            << " = " << actual_result << std::endl;
            std::cout << "Expected result data: " << expected_result->data << std::endl;
            std::cout << "Actual result data: " << actual_result->data << std::endl;  
            std::cout << std::endl << "<---------------------------------------------->\n\n";
        }
        delete expected_result;
        return 0;
    }
    if( detail == true){
        std::cout << RED << "Big int data test: Wrong output!\n";
        std::cout << std::endl << "<---------------------------------------------->\n\n";
    }
    delete expected_result;
    return 1;
}

int main(int argc, char **argv){
    if(argc > 2){
        std::cerr << "Too many arguments\n";
        return(1);
    }
    bool detail;
    if(argc > 1 && !strcmp(argv[1], "-d"))
        detail = true;
    else if (argc > 1){
        std::cerr << "Not a valid flag, did you mean -d?\n";
        return(1);
    }
    else
        detail = false;
    int number_of_tests = 4;
    int (*tests[])(bool) = {&null_data_test, &new_data_test, &init_data_test, &bigint_data_test};
    int fail = 0;
    for(int i = 0; i < number_of_tests; i++){
        if(tests[i](detail))
            fail++;
    }
    if(fail)
        std::cout << RED << "Failure: " << number_of_tests << " tests performed, " << fail << " fails" << RESET << std::endl;
    else
        std::cout << GREEN << "Sucess: " << number_of_tests << " tests performed, 0 fails" 
        << RESET << " (run with -d to see tests in detail)" << std::endl;
}