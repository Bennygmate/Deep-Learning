//Bennygmate
#include "TMatrix.h"

namespace neurons {
    class NN_layer_op;
    class NN_layer {
    public:
        static const std::string NN;
        static const std::string FCNN;
        static const std::string CNN;
        static const std::string RNN;
    protected:
        mutable std::vector<std::shared_ptr<NN_layer_op>> m_ops;
    public:
        NN_layer();
        NN_layer(lint threads);
        NN_layer(const NN_layer & other);
        NN_layer(NN_layer && other);
        NN_layer & operator = (const NN_layer & other);
        NN_layer & operator = (NN_layer && other);
        std::vector<std::shared_ptr<NN_layer_op>>& operation_instances() const;
        virtual double commit_training();
        virtual double commit_testing();
        virtual Shape output_shape() const = 0;
        virtual std::unique_ptr<char[]> to_binary_data(lint & data_size) const = 0;
        virtual std::string nn_type() const = 0;
    };

    class NN_layer_op {
    protected:
        double m_loss;

    public:
        NN_layer_op();
        NN_layer_op(const NN_layer_op & other);
        NN_layer_op(NN_layer_op && other);
        NN_layer_op & operator = (const NN_layer_op & other);
        NN_layer_op & operator = (NN_layer_op && other);
    public:
        // Forward prop
        virtual TMatrix<> forward_propagate(const TMatrix<> &input) = 0;
        virtual TMatrix<> forward_propagate(const TMatrix<> &input, const TMatrix<> &target) = 0;
        // Back prop
        virtual TMatrix<> back_propagate(double l_rate, const TMatrix<> & E_to_y_diff) = 0;
        virtual TMatrix<> back_propagate(double l_rate) = 0;

		// Batch Forward prop
        virtual std::vector<TMatrix<>> batch_forward_propagate(const std::vector<TMatrix<>> & inputs) = 0;
        virtual std::vector<TMatrix<>> batch_forward_propagate(const std::vector<TMatrix<>> & inputs, const std::vector<TMatrix<>> & targets) = 0;
        // Batch Back propg
        virtual std::vector<TMatrix<>> batch_back_propagate(double l_rate, const std::vector<TMatrix<>> & E_to_y_diffs) = 0;
        virtual std::vector<TMatrix<>> batch_back_propagate(double l_rate) = 0;
        virtual Shape output_shape() const = 0;

        double get_loss() const;

        void clear_loss();
    };
}

