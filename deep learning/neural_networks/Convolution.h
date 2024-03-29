//Bennygmate
#include "TMatrix.h"

namespace neurons{
    class Conv_1d    {
    private:
        mutable TMatrix<> m_diff_to_w;

        Shape m_input_sh;
        Shape m_weights_sh;

        lint m_stride;

    public:
        Conv_1d(const Shape & input_shape, const Shape & weights_shape, lint stride = 1);
        Conv_1d();
        ~Conv_1d();

        TMatrix<> operator () (const TMatrix<> & input, const TMatrix<> & weights, const TMatrix<> & bias);

        TMatrix<> & get_diff_to_weights() const;
    };

    class Conv_2d    {
    private:

        Shape m_input_sh;
        Shape m_ex_in_sh;
        Shape m_weights_sh;
        Shape m_output_sh;

        lint m_r_stride;
        lint m_c_stride;

        lint m_r_zero_p;
        lint m_c_zero_p;

        mutable TMatrix<> m_diff_to_w;
        mutable TMatrix<> m_diff_to_x;


    
    public:
        Conv_2d(const Shape & input_shape, const Shape & weights_shape, lint r_stride = 1, lint c_stride = 1, lint r_zero_p = 0, lint c_zero_p = 0);
        Conv_2d();
        ~Conv_2d();

        TMatrix<> operator () (const TMatrix<> & input, const TMatrix<> & weights, const TMatrix<> & bias);

        TMatrix<> & get_diff_to_weights() const;

        TMatrix<> & get_diff_to_input() const;

        Shape get_output_shape() const;

    public:
        TMatrix<> zero_padding(const TMatrix<> & input);
        lint r_stride() const { return this->m_r_stride; }
        lint c_stride() const { return this->m_c_stride; }
        lint r_zero_p() const { return this->m_r_zero_p; }
        lint c_zero_p() const { return this->m_c_zero_p; }
    };

    class Conv_3d {};
}

